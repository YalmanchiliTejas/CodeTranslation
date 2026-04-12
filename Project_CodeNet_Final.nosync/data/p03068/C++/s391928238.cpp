#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long int
#define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n)

using namespace std;

int main()
{
    string s;
    int n, k;
    cin >> n >> s >> k;
    REP(i,n){
        if(s[i] != s[k-1]) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}
