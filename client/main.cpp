#include "Python.h"
#include <iostream>

// data to be printed by callback
char *message = "Hello from a C++ Callback!";

// Prints data above
PyObject* print_message(PyObject *self, PyObject *args)
{
    std::cout << message << std::endl;
    return Py_None;
}

// Array of method definitions for module
PyMethodDef TestMethods[] = {
    {"call", print_message, METH_NOARGS, "Calls back to c++."},
    {NULL, NULL, 0, NULL}
};

// Module definition
PyModuleDef TestModule = {
    PyModuleDef_HEAD_INIT, "test_callback", NULL, -1, TestMethods,
    NULL, NULL, NULL, NULL
};

// Method to initialize the module
PyObject* PyInit_test_callback(void)
{
    return PyModule_Create(&TestModule);
}

int main(int argc, char* argv[])
{
    // Show we can print from C++
    std::cout << "Hello from C++" << std::endl;
    // Will add test_callback module to interpreter
    PyImport_AppendInittab("test_callback", &PyInit_test_callback);
    // Starts interpreter
    Py_Initialize();
    // Print hello world message from python
    PyRun_SimpleString("print('Hello from Python!')");
    // Makes the call back into the C++ application
    PyRun_SimpleString("import test_callback");
    PyRun_SimpleString("test_callback.call()");
    // Ends interpreter
    Py_Finalize();
}