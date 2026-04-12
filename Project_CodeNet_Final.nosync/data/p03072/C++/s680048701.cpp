#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a[25];
    int n;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int sum=1;
    int most=a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]>=most)
        {
            sum++;
            most=a[i];
        }
    }
    cout << sum <<endl;
}
