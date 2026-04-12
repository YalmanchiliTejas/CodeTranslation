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
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;

    char numberK = S[K-1];
    for(int i = 0; i < S.size(); i++)
    {
        if (S[i] != numberK)
        {
            S[i] = '*';
        }
        else
        {
            
        }
        
    }
    cout << S << endl;
}