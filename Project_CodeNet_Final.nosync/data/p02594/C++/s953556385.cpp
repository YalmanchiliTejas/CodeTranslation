#include <iostream>

using namespace std;

int main()
{
    long X;
    cin >> X;

    if (X >= 30 && X <= 40) {
        std::cout << "Yes" << std::endl;
    }
    if (X >= -40 && X < 30){
        std::cout << "No" << std::endl;
    }

}