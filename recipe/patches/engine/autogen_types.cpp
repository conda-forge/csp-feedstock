
#include "autogen_types.h"
#include <csp/python/Common.h>
#include <csp/python/PyStruct.h>
#include <csp/python/PyCspEnum.h>
#include <iostream>
#include <stdlib.h>
#include <Python.h>

namespace csp::autogen
{

#define _offsetof( C, M ) ( ( char * ) &( ( C * ) nullptr ) -> M - ( char * ) 0 )

static void assert_or_die( bool assertion, const char * error )
{
    if( !assertion )
    {
        std::cerr << "Fatal error on import of " << __FILE__ << ": " << error << std::endl;
        if( PyErr_Occurred() )
            PyErr_Print();
        abort();
    }
}


bool TimeIndexPolicy::static_init()
{
    if( Py_IsInitialized() )
    {
        csp::python::AcquireGIL gil;

        // initialize EnumMeta from python type if we're in python
        PyObject * pymodule = PyImport_ImportModule( "csp.impl.types.autogen_types" );
        assert_or_die( pymodule != nullptr, "failed to import struct module csp.impl.types.autogen_types" );

        PyObject * enumType = PyObject_GetAttrString(pymodule, "TimeIndexPolicy" );
        assert_or_die( enumType != nullptr, "failed to find num type TimeIndexPolicy in module csp.impl.types.autogen_types" );

        // should add some assertion here..
        csp::python::PyCspEnumMeta * pymeta = ( csp::python::PyCspEnumMeta * ) enumType;
        s_meta = pymeta -> enumMeta;
    }

    return true;
}

bool static_init_TimeIndexPolicy = TimeIndexPolicy::static_init();
std::shared_ptr<csp::CspEnumMeta> TimeIndexPolicy::s_meta;
TimeIndexPolicy TimeIndexPolicy::INCLUSIVE = TimeIndexPolicy::create("INCLUSIVE");
TimeIndexPolicy TimeIndexPolicy::EXCLUSIVE = TimeIndexPolicy::create("EXCLUSIVE");
TimeIndexPolicy TimeIndexPolicy::EXTRAPOLATE = TimeIndexPolicy::create("EXTRAPOLATE");


bool DynamicBasketEvent::static_init()
{

    if( Py_IsInitialized() )
    {
        //Note that windows requires we grab the GIL since the windows DLL loading code releases GIL
        csp::python::AcquireGIL gil;

        // initialize StructMeta from python type if we're in python
        PyObject * pymodule = PyImport_ImportModule( "csp.impl.types.autogen_types" );
        assert_or_die( pymodule != nullptr, "failed to import struct module csp.impl.types.autogen_types" );

        PyObject * structType = PyObject_GetAttrString(pymodule, "DynamicBasketEvent" );
        assert_or_die( structType != nullptr, "failed to find struct type DynamicBasketEvent in module csp.impl.types.autogen_types" );

        // should add some assertion here..
        csp::python::PyStructMeta * pymeta = ( csp::python::PyStructMeta * ) structType;
        s_meta = pymeta -> structMeta;
    }

    return true;
}

bool static_init_DynamicBasketEvent = DynamicBasketEvent::static_init();
csp::StructMetaPtr DynamicBasketEvent::s_meta;


bool DynamicBasketEvents::static_init()
{

    if( Py_IsInitialized() )
    {
        //Note that windows requires we grab the GIL since the windows DLL loading code releases GIL
        csp::python::AcquireGIL gil;

        // initialize StructMeta from python type if we're in python
        PyObject * pymodule = PyImport_ImportModule( "csp.impl.types.autogen_types" );
        assert_or_die( pymodule != nullptr, "failed to import struct module csp.impl.types.autogen_types" );

        PyObject * structType = PyObject_GetAttrString(pymodule, "DynamicBasketEvents" );
        assert_or_die( structType != nullptr, "failed to find struct type DynamicBasketEvents in module csp.impl.types.autogen_types" );

        // should add some assertion here..
        csp::python::PyStructMeta * pymeta = ( csp::python::PyStructMeta * ) structType;
        s_meta = pymeta -> structMeta;
    }

    return true;
}

bool static_init_DynamicBasketEvents = DynamicBasketEvents::static_init();
csp::StructMetaPtr DynamicBasketEvents::s_meta;

}
