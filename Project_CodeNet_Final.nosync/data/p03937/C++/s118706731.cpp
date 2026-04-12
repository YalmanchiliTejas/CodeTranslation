#include "bits/stdc++.h"
using namespace std;
#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
typedef long long ll;

const int INF = 1e9 + 7;
const long long LLINF = 1e18;

ll h, w;
string a[10];
int main() {
    cin>>h>>w;
    REP(i, 0, h) cin>>a[i];

    ll cnt=0;
    REP(i, 0, h){
        REP(j, 0, w){
            if(a[i][j]=='#') cnt++;
        }
    }
    if(cnt==h+w-1) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}