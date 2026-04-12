#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <string>

int main()
{

    int x, y, z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    int people;

    people = (x - z) / (y + z);

    std::cout << people << "\n";

    return 0;
}