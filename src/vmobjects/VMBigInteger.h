#ifndef VMBIGINTEGER_H_
#define VMBIGINTEGER_H_

/*
 * $Id: VMBigInteger.h 168 2008-01-03 14:05:26Z tobias.pape $
 *
Copyright (c) 2007 Michael Haupt, Tobias Pape
Software Architecture Group, Hasso Plattner Institute, Potsdam, Germany
http://www.hpi.uni-potsdam.de/swa/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
  */

#include <vmobjects/VMObject.h>

#pragma mark VTable definition

VTABLE(VMBigInteger) {
#define VMBIGINTEGER_VTABLE_FORMAT \
    VMOBJECT_VTABLE_FORMAT; \
    int64_t (*get_embedded_biginteger)(void*)
        
    VMBIGINTEGER_VTABLE_FORMAT;
};

#pragma mark class definition

struct _VMBigInteger {
    VTABLE(VMBigInteger)* _vtable;
    
#define BIGINTEGER_FORMAT \
    VMOBJECT_FORMAT; \
    int64_t embedded_biginteger
    
    BIGINTEGER_FORMAT;
};

#pragma mark class methods

pVMBigInteger VMBigInteger_new(void);
pVMBigInteger VMBigInteger_new_with(const int64_t);

#pragma mark vtable initialization

VTABLE(VMBigInteger)* VMBigInteger_vtable(void);

#endif // VMBIGINTEGER_H_
