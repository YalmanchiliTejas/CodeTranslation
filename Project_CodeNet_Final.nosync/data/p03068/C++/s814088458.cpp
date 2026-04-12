#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)

int main(void)
{
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    
    char s = S[K-1];
    for(int i = 0; i < N; i++)
    {
        if(S[i] != s)
        {
            S[i] = '*';
        }
    }
    cout << S << endl;

    return 0;

}
