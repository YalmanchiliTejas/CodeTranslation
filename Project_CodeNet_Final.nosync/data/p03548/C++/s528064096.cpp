#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int X, Y, Z;
    std::cin >> X >> Y >> Z;
    int count = 0;

    while(1) {
        //X -= (Y+Z);
        
        if ((count+1) * (Y + Z) + Z > X) {
            break;
        }
      count++;
    }

    /*
    if ((X - count *(Y+Z) + Z) < 0) {
        count--;
    } else {
        ;
    }
    */
    std::cout << count << std::endl;
    return 0;
}