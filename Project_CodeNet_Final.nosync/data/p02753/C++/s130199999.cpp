#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str == "AAA" | str == "BBB")
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }

    return 0;
}