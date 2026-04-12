#include <iostream>

int main(int argc, char** argv)
{
    int a, b;
    std::cin >> a >> b;

    char* compareResult;
    if (a < b) {
        compareResult = "<";
    } else if (a > b){
        compareResult = ">";
    } else {
        compareResult = "==";
    }

    std::cout << "a " << compareResult << " b" << std::endl;

    return 0;
}