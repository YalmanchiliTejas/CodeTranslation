#include <stdio.h>
#include <iostream>

int main(int argc, char** argv)
{
    int iMax=-1;
    int counter=0;
    int N;
    int H;
    std::cin >> N;
    for(int i=0;i<N;i++)
    {
        std::cin >> H;
        if(H >= iMax)
        {
            iMax=H;
            counter++;
        }
    }
    std::cout << counter;
    
    return 0;
}