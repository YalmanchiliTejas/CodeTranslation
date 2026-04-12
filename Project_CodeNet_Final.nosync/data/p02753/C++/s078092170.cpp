#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
#define FOR(i, a, b) for(LL i=(LL)(a);i<(LL)(b);i++)
#define REP(i,x) for(LL i=0;i<(LL)(x);i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    string S;
    cin >> S;

    if(S == "AAA" || S == "BBB")
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    
    return 0;
}