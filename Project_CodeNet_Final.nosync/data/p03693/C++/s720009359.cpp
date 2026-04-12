#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int r, g, b; cin >> r >> g >> b;
    string s = to_string(r) + to_string(g) + to_string(b);
    if(stoi(s)%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}