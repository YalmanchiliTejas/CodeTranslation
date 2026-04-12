#include <bits/stdc++.h>
#define FOR(i,bg,ed) for(ll i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;
const int INF = 1e9;



signed main()
{
    char c;
    cin >> c;
    
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}
