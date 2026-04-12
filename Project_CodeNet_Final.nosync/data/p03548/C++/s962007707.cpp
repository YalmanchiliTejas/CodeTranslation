#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cctype>
#include <map>
#include <queue>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ll long long

int main()
{
    int x,y,z;
    cin >> x >> y >> z;

    int sumSpace = z;
    int sitPeopleNum = 0;
    while (true)
    {
        sumSpace += y + z;
        if (sumSpace > x)
        {
            break;
        }
        sitPeopleNum++;
    }
    
    cout << sitPeopleNum << endl;
}