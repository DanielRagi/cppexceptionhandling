#define _WIN32_WINNT 0x0501
#include <mingw.thread.h>
#include <iostream>
#include <system_error>

void independentThread() 
{
    std::cout << "Iniciando ejecucion de hilo concurrente.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Finalizando ejecucion de hilo concurrente.\n";
}
 
int main()
{
    std::thread().detach();

    std::cout << "Iniciando creacion de hilos.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Finalizando creacion de hilos.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}