#include "myshell.h"

os_cp_1::myshell::myshell():PROMPT("myshell>> ")
{
}


os_cp_1::myshell::~myshell()
{
}


void os_cp_1::myshell::run()
{
    while( true ){
        get_input();

        if( input_buffer == "exit" ) break; 

        else if( !input_buffer.empty() ){ 
            pid_t pid = fork();
            if( pid == 0 ){
                execute_command();
                break;
            } else if( pid < 0 ){
                std::cerr << "There was an error creating a child process.";
            } else {
                wait(NULL);
            }
        }
    }
}

unsigned os_cp_1::myshell::get_input(){
    std::cout << PROMPT;
    std::getline( std::cin, input_buffer );
}

void os_cp_1::myshell::execute_command(){
    system( input_buffer.c_str() );
}