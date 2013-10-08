#define _POSIX_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

namespace os_cp_1 {
    class myshell
    {
    public:
        myshell();
        virtual ~myshell();

        void run();

    protected:
        /**** Functions ****/
        unsigned get_input();
        void execute_command();

        /**** Constants ****/
        const std::string PROMPT; 

        /**** Variables ****/
        std::string input_buffer;
        std::string* argument_list;
    };

}