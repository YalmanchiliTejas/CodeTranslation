#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)

int main()
{
    int N;
    cin >> N;

    int H[N];
    int max_H = 0;
    int count = 0;
    REP(i, N)
    {
        cin >> H[i];
        if (max_H <= H[i])
        {
            max_H = H[i];
            count++;
        }
    }

    cout << count << endl;
}