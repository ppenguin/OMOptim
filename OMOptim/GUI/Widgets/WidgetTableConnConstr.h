﻿// $Id$
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

 	@file WidgetTableConnConstr.h
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 
*/

#ifndef WIDGETTABLECONNCONSTR_H
#define WIDGETTABLECONNCONSTR_H

#include <QtGui/QDialog>
#include <QtGui/QWidget>
#include<QtGui/QFileDialog>

#include "MyDelegates.h"
#include "EIConnConstrs.h"
#include "MOTableView.h"
#include "GuiTools.h"

namespace Ui {
    class WidgetTableConnConstrClass;
}


class QErrorMessage;


class WidgetTableConnConstr : public QWidget {
    Q_OBJECT


public:
        explicit WidgetTableConnConstr(EIConnConstrs *constrs, EITree* _eiTree,bool _editable,QWidget *parent = 0);
    virtual ~WidgetTableConnConstr();

	public slots:
		void onPushAdd();
		void updateCompleters();
		void onPushRemove();
public:
    Ui::WidgetTableConnConstrClass *ui;
	EIConnConstrs* constrs;
	MOTableView* tableView;
        EITree* eiTree;
	
	VarCompleterDelegate *compltDlgA;
	VarCompleterDelegate *compltDlgB;
	GenericDelegate* typeDlg;

	bool editable;
};

#endif 
