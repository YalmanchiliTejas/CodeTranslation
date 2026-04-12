#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;

ll h, w;
char a[101][101];
bool flag[101][101];
bool skip[101];
int main() {
    cin>>h>>w;
    REP(i, 0, h) REP(j, 0, w){
        cin>>a[i][j];
    }

    REP(i, 0, h){
        bool f=false;
        REP(j, 0, w){
            if(a[i][j]=='#') f=true;
        }

        if(!f){
            REP(j, 0, w) flag[i][j]=true;
            skip[i]=true;
        }
    }

    REP(j, 0, w){
        bool f=false;
        REP(i, 0, h){
            if(a[i][j]=='#') f=true;
        }

        if(!f){
            REP(i, 0, h) flag[i][j]=true;
        }
    }

    REP(i, 0, h){
        REP(j, 0, w){
            if(!flag[i][j]) cout<<a[i][j];
        }
        if(!skip[i]) cout<<endl;
    }

    return 0;
}