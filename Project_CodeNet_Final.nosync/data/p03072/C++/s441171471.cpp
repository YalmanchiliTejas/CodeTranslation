#include <bits/stdc++.h>

#define NMAX 1000
#define MAX(a, b) (a > b ? a : b)

using namespace std;

//ifstream fin("f.in");
//ofstream fout("f.out");

int nInns;
int height[21];
int currentMax;
int goodInns;

int main()
{
    cin >> nInns;
    for(int i = 0; i < nInns; i++)
        cin >> height[i];
    currentMax = height[0];
    goodInns = 1;

    for(int i = 1; i < nInns; i++)
    {
        if(height[i] >= currentMax)
        {
            goodInns++;
            currentMax = height[i];
        }
    }

    cout << goodInns << '\n';
    return 0;
}
