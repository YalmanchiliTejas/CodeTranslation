// atc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include    <algorithm>
using namespace std;

//int n, m, x;
//
//vector<int> c(12,0);
//vector<vector<int>> A(12, vector<int>(12, 0));



int main()
{
    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;
    int sum;
    int min = 2147483647;

    int dai = (x > y ? x : y);

    for (int i = 0; i < dai+1; i++) {
        int x2 = (x - i > 0 ? x - i : 0);
        int y2 = (y - i > 0 ? y - i : 0);

        sum = a * (x2) + b * (y2) + ab * i * 2;

        if (sum < min) {
            min = sum;
        }
    }


    printf("%d", min);


    return 0;

}