/**************************************************************************
 *  This file is part of QXmlEdit                                         *
 *  Copyright (C) 2016 by Luca Bellonda and individual contributors       *
 *    as indicated in the AUTHORS file                                    *
 *  lbellonda _at_ gmail.com                                              *
 *                                                                        *
 * This library is free software; you can redistribute it and/or          *
 * modify it under the terms of the GNU Library General Public            *
 * License as published by the Free Software Foundation; either           *
 * version 2 of the License, or (at your option) any later version.       *
 *                                                                        *
 * This library is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 * Library General Public License for more details.                       *
 *                                                                        *
 * You should have received a copy of the GNU Library General Public      *
 * License along with this library; if not, write to the                  *
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
 * Boston, MA  02110-1301  USA                                            *
 **************************************************************************/

#include "scxmlroot.h"
#include "ui_scxmlroot.h"
#include "regola.h"
#include "modules/specialized/scxml/scxmltoken.h"
#include "modules/xsd/namespacemanager.h"
#include "utils.h"

SCXMLRoot::SCXMLRoot(QWidget *parent, SCXMLInfo *info, Regola *regola, const bool isInsertOrEdit, const bool isInsertOrAppend,
                     Element *toModifyElement, Element *selectedElement, Element *parentElement) :
    QDialog(parent),
    _isInsertOrEdit(isInsertOrEdit),
    _isInsertOrAppend(isInsertOrAppend),
    _d(toModifyElement),
    ui(new Ui::SCXMLRoot)
{
    _regola = regola;
    _info = info ;
    _selectedElement = selectedElement;
    _parentElement = parentElement;
    ui->setupUi(this);
    setupCommon();
    if(_isInsertOrEdit) {
        setupInsert();
    }
    setupEdit();
}

SCXMLRoot::~SCXMLRoot()
{
    delete ui;
}

void SCXMLRoot::setupCommon()
{
    Utils::TODO_THIS_RELEASE("fare");
    Utils::loadComboTextArrays(ui->initial, "", _info->allStates(), _info->allStates());
}

// use default values
void SCXMLRoot::setupInsert()
{
    Utils::TODO_THIS_RELEASE("fare");
    _d.setAttributeString(SCXMLscxmlToken::A_binding, "early");
    _d.setAttributeString(SCXMLscxmlToken::A_datamodel, "null" );
    _d.setAttributeString(SCXMLscxmlToken::A_name, tr("New Machine"));
    _d.setAttributeString(SCXMLscxmlToken::A_version, "1.0");
    _d.setAttributeString(SCXMLscxmlToken::A_xmlns, NamespaceManager::SCXMLNamespace);
    _d.assignTag(SCXMLToken::Tag_scxml, _regola, _parentElement);
}

void SCXMLRoot::setupEdit()
{
    //fai fill su elemento se insert, poi una sola funzione per settare UI.

    Utils::TODO_THIS_RELEASE("fare");
    ui->binding->setChecked(_d.attributeString(SCXMLscxmlToken::A_datamodel, "early")!= "late");
    ui->datamodel->setEditText(_d.attributeString(SCXMLscxmlToken::A_datamodel));
    ui->name->setText(_d.attributeString(SCXMLscxmlToken::A_name));
    ui->version->setText(_d.attributeString(SCXMLscxmlToken::A_version));
    ui->initial->setEditText(_d.attributeString(SCXMLscxmlToken::A_initial));
}

void SCXMLRoot::accept()
{
    Utils::TODO_THIS_RELEASE("fare validazioni");
    Utils::TODO_THIS_RELEASE("controlla obbligatori");
    Utils::TODO_THIS_RELEASE("set dati in elemento");
    Utils::TODO_THIS_RELEASE("aggiungi attributi obbligatori");

    _d.setAttributeString(SCXMLscxmlToken::A_binding, ui->binding->isChecked()?"early":"late");
    _d.setAttributeString(SCXMLscxmlToken::A_datamodel, ui->datamodel->currentText() );
    _d.setAttributeString(SCXMLscxmlToken::A_name, ui->name->text());
    _d.setAttributeString(SCXMLscxmlToken::A_version, ui->version->text());
    _d.setAttributeString(SCXMLscxmlToken::A_xmlns, NamespaceManager::SCXMLNamespace);
    _d.setAttributeString(SCXMLscxmlToken::A_initial, ui->initial->currentText());
    //_d.setAttributeStringIfMissing(SCXMLscxmlToken::A_xmlns, NamespaceManager::SCXMLNamespace);

    if(     !_d.checkIDREFS(this, SCXMLscxmlToken::A_initial)
        ||  !_d.checkNMTOKEN(this, SCXMLscxmlToken::A_name)
        ||  !_d.checkNMTOKEN(this, SCXMLscxmlToken::A_datamodel)) {
        return;
    }

    QDialog::accept();
}
