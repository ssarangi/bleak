#include <iostream>
#include <thread>

void display()
{
	std::cout << "Display from here" << std::endl;
}

int main()
{
    std::thread t(display);
    t.join();
    return 1;
}
