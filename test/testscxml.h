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

#ifndef TESTSCXML_H
#define TESTSCXML_H

#include "testbase.h"

class TestSCXML : public TestBase
{
    bool testTemplatesCompile();
    bool testTemplatesLoadStates();
    //---
    bool setEAE(QWidget *widget, const QString &name, const QString &attr, const QString value, Element *e1);
    bool setEAC(QWidget *widget, const QString &name, const QString &attr, const QString value, Element *e1);
    bool setEAB(QWidget *widget, const QString &name, const bool checked, const QString &attr, const QString value, Element *e1);
    //---
    bool testEditassign();
    bool testEditcancel();
    bool testEditcontent();
    bool testEditdata();
    bool testEditdatamodel();
    bool testEditelse();
    bool testEditelseif();
    bool testEditraise();
    bool testEditfinal();
    bool testEditfinalize();
    bool testEdithistory();
    bool testEditif();
    bool testEditinitial();
    bool testEditinvoke();
    bool testEditforeach();
    bool testEditlog();
    bool testEditonentry();
    bool testEditonexit();
    bool testEditparallel();
    bool testEditparam();
    bool testEditscript();
    bool testEditscxml();
    bool testEditsend();
    bool testEditstate();
    bool testEdittransition();
    bool testEditvar();
public:
    TestSCXML();
    ~TestSCXML();

    bool testFast();
    bool testLoadTokens();
    bool testEditTokens();
    bool testTemplates();
};

#endif // TESTSCXML_H
