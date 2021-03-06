// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL).
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)

        @file MOParameter.h
     @brief Comments for file documentation.
     @author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
     Company : CEP - ARMINES (France)
     http://www-cep.ensmp.fr/english/
     @version

  */
#if !defined(_MOParameter_H)
#define _MOParameter_H

#include "MOItem.h"
#include "MOVector.h"
#include "QtCore/QMap"


/**
 *  Class for parameter storage. A parameter can be used e.g. for Simulator configuration, Optimization configuration...
 *  Value of parameter is of type QVariant.
 *  Inherits MOItem.
 */
class MOParameter : public MOItem
{
public:

    enum Field
    {
        //Modelica fields
        NAME,
        VALUE,
        DEFAULTVALUE,
        TYPE,
        MIN,
        MAX,
        DESCRIPTION,
        //INDEX, // index in OpenModelica parameters or in Dymola parameters (e.g. OpenModelica::STOPVALUE)
        GROUP, // used to display parameter in separated groupbox
        PANEL   // used to display parameter in separated panel
    };


    enum Type
    {
        FOLDERPATH,
        FILEPATH,
        STRING,
        BOOL,
        INT,
        DOUBLE,
        LIST
    };

    MOParameter();
    MOParameter(const MOParameter &);
    MOParameter(QString name,QString desc,QVariant defaultValue, Type type, QVariant minValue=0, QVariant maxValue=std::numeric_limits<int>::max(),QString enablingIndex=QString(),QVariant enablingValue = true,QString group="");
    //MOParameter(QString);
    MOParameter(QDomElement & domEl);
    virtual ~MOParameter(void);

    virtual QString getClassName() const {return "MOParameter";};

    static const int nbFields = 9;
    virtual unsigned getNbFields( ) const {return nbFields;};


    virtual bool setFieldValue(int iField,QVariant _value);
    virtual QVariant getFieldValue(int ifield, int role = Qt::UserRole) const;
    static QString sFieldName(int ifield, int role);
    virtual QString getFieldName(int i, int role = Qt::DisplayRole) const {return MOParameter::sFieldName(i,role);};

    virtual MOParameter* clone() const;

    void addEnablingIndex(QString index,QVariant enablingValue);
    QMap<QString,QVariant> enablingIndexes() const;
    //int index(){return _index;}


    QVariant value(){return getFieldValue(VALUE);};
    QString description(){return _description;};

    virtual QDomElement toXmlData(QDomDocument & doc);
    virtual void update(QDomElement & domEl);

protected :
    QString _description;
    QVariant _value;
    QVariant _defaultValue;
    Type _type;
    QVariant _min;
    QVariant _max;
    //int _index;
    QMap<QString,QVariant> _enablingIndexes; /** map of enabling parameter (the one indexed by key) that enable this one.
            QVariant corresponds to the value the enabling parameter should take to enable this parameter*/

    QString _group;
    QString _panel;
};

/**
* \brief Corresponds to a MOParameter in which value is among a list.
* @warning _value stores int value (key of map) and not string value
*/
class MOParameterListed : public MOParameter
{
public:

    enum Field
    {
        //Modelica fields
        NAME,
        VALUE,
        DEFAULTVALUE,
        TYPE,
        MIN,
        MAX,
        DESCRIPTION,
        //INDEX, // index in OpenModelica parameters or in Dymola parameters (e.g. OpenModelica::STOPVALUE)
        GROUP,
        PANEL
    };



    MOParameterListed();
    MOParameterListed(const MOParameterListed &);
    MOParameterListed(QString name,QString desc,QVariant defaultValue, QMap<int,QString> mapList,QString enablingIndex=QString(),QVariant enablingValue = true);
    //MOParameterListed(QString);
    MOParameterListed(QDomElement & domEl);
    ~MOParameterListed(void);
    virtual MOParameterListed* clone() const;

    virtual QString getClassName() const {return "MOParameterListed";};

    static const int nbFields = 9;
    virtual unsigned getNbFields( ) const {return nbFields;};


    bool setFieldValue(int iField,QVariant _value);
    QVariant getFieldValue(int ifield, int role = Qt::UserRole) const;
    QString sFieldName(int ifield, int role);
    QString getFieldName(int i, int role = Qt::DisplayRole) const {return MOParameter::sFieldName(i,role);};

    QMap<int,QString> mapList(){return _mapList;};
    QString strValue();

private :
    QMap<int,QString> _mapList; // for list parameters (e.g. algorithm between dassl and euler)
};

class MOParameters : public MOVector<MOParameter>
{
    Q_OBJECT
public :
    MOParameters();
    MOParameters(const MOParameters & );
    virtual ~MOParameters();
    QVariant value(QString name,QVariant defaultValue = QVariant()) const;
    bool setValue(QString name,QVariant value);
    QMultiMap<QString,MOParameter*> groupmap() const;
    void setGroup(QString group,QStringList indexes);
    void setPanel(QString panel);
    void addEnablingIndex(QStringList enabledIndexes,QString enablingIndex, QVariant enablingValue);
    bool shouldBeEnabled(QString name);
    MOParameters* clone() const;

    bool operator==(const MOParameters& b)const;

signals :
    void modified();

private :
    QVariant value(int ,QVariant defaultValue = QVariant()) const;

};






#endif
