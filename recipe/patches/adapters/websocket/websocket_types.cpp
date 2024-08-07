
#include "websocket_types.h"
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


bool WebsocketStatus::static_init()
{
    if( Py_IsInitialized() )
    {
        csp::python::AcquireGIL gil;

        // initialize EnumMeta from python type if we're in python
        PyObject * pymodule = PyImport_ImportModule( "csp.adapters.websocket_types" );
        assert_or_die( pymodule != nullptr, "failed to import struct module csp.adapters.websocket_types" );

        PyObject * enumType = PyObject_GetAttrString(pymodule, "WebsocketStatus" );
        assert_or_die( enumType != nullptr, "failed to find num type WebsocketStatus in module csp.adapters.websocket_types" );

        // should add some assertion here..
        csp::python::PyCspEnumMeta * pymeta = ( csp::python::PyCspEnumMeta * ) enumType;
        s_meta = pymeta -> enumMeta;
    }

    return true;
}

bool static_init_WebsocketStatus = WebsocketStatus::static_init();
std::shared_ptr<csp::CspEnumMeta> WebsocketStatus::s_meta;
WebsocketStatus WebsocketStatus::ACTIVE = WebsocketStatus::create("ACTIVE");
WebsocketStatus WebsocketStatus::GENERIC_ERROR = WebsocketStatus::create("GENERIC_ERROR");
WebsocketStatus WebsocketStatus::CONNECTION_FAILED = WebsocketStatus::create("CONNECTION_FAILED");
WebsocketStatus WebsocketStatus::CLOSED = WebsocketStatus::create("CLOSED");
WebsocketStatus WebsocketStatus::MESSAGE_SEND_FAIL = WebsocketStatus::create("MESSAGE_SEND_FAIL");


bool WebsocketHeaderUpdate::static_init()
{

    if( Py_IsInitialized() )
    {
        //Note that windows requires we grab the GIL since the windows DLL loading code releases GIL
        csp::python::AcquireGIL gil;

        // initialize StructMeta from python type if we're in python
        PyObject * pymodule = PyImport_ImportModule( "csp.adapters.websocket_types" );
        assert_or_die( pymodule != nullptr, "failed to import struct module csp.adapters.websocket_types" );

        PyObject * structType = PyObject_GetAttrString(pymodule, "WebsocketHeaderUpdate" );
        assert_or_die( structType != nullptr, "failed to find struct type WebsocketHeaderUpdate in module csp.adapters.websocket_types" );

        // should add some assertion here..
        csp::python::PyStructMeta * pymeta = ( csp::python::PyStructMeta * ) structType;
        s_meta = pymeta -> structMeta;
    }

    return true;
}

bool static_init_WebsocketHeaderUpdate = WebsocketHeaderUpdate::static_init();
csp::StructMetaPtr WebsocketHeaderUpdate::s_meta;

}
