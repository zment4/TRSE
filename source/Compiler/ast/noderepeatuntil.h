#ifndef NODEREPEATUNTIL_H
#define NODEREPEATUNTIL_H

/*
 * Turbo Rascal Syntax error, “;” expected but “BEGIN” (TRSE, Turbo Rascal SE)
 * 8 bit software development IDE for the Commodore 64
 * Copyright (C) 2018  Nicolaas Ervik Groeneboom (nicolaas.groeneboom@gmail.com)
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program (LICENSE.txt).
 *   If not, see <https://www.gnu.org/licenses/>.
*/


#include "source/Compiler/token.h"
#include "source/Compiler/pvar.h"
#include "source/Compiler/symboltable.h"
#include "source/Compiler/errorhandler.h"
#include "source/Compiler/ast/node.h"
#include "source/Compiler/ast/nodebinaryclause.h"
#include <QVector>
#include "source/Compiler/codegen/abstractcodegen.h"

class NodeRepeatUntil : public Node {
public:

//    QVector<QSharedPointer<Node>> m_a, m_b;

    QSharedPointer<Node> m_block = nullptr;
    QSharedPointer<NodeBinaryClause> m_clause = nullptr;


    NodeRepeatUntil(Token op, int forcePage,  QSharedPointer<NodeBinaryClause> cond, QSharedPointer<Node> block);




    void ExecuteSym(QSharedPointer<SymbolTable> symTab) override {
       m_block->ExecuteSym(symTab);
    }

    void Accept(AbstractCodeGen* dispatcher) override {
        dispatcher->dispatch(qSharedPointerDynamicCast<NodeRepeatUntil>(sharedFromThis()));
    }


};


#endif // NODEREPEATUNTIL_H
