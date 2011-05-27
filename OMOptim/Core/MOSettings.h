// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Link�pings universitet, Department of Computer and Information Science,
 * SE-58183 Link�ping, Sweden.
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

 	@file MOSettings.h
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 

  */
#ifndef MOSETTINGS_H
#define MOSETTINGS_H

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QSettings>
#include <QtCore/QDir>
#include <QtCore/QVector>





class MOSettings
{
public:
	enum type
	{
		FOLDERPATH,
		FILEPATH,
		STRING,
		BOOL,
		INT,
		DOUBLE
	};
public:
	MOSettings(void);
	~MOSettings(void);




	static void initialize(bool eraseCurrentValues);

	



	static QStringList names;
	static QStringList descs;
	static QVector<int> types;
	static QVariantList defaultValues;
	
	static void setValue(QString, QVariant);
	static void setValue(int, QVariant);
	static QVariant getValue(QString);
	static QVariant getValue(int);


	// trick to have a "purely" static class
	static MOSettings instance;
};


#endif
