#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define mset(a,x) memset(a,x,sizeof(a))
#define dbg(x) cout<<#x<<": "<<(x)<<"\n"
#define pb push_back
#define mp make_pair

int h,w;
int px=0, py=0;
int dx[]={1,0}, dy[]={0,1};
vector<string> v;

bool check() {
    rep(y,h) {
        rep(x,w){
            if(v[y][x]=='#') {
                if(x==0 or y==h-1) continue;
                if(v[y+1][x-1] == '#') return false;
            }
        }
    }
    return true;
}

int main() {
    while(cin>>h>>w) {
        v.resize(h);
        rep(i,h) cin>>v[i];

        if(check()) {
            puts("Possible");
        } else {
            puts("Impossible");
        }
    }
    return 0;
}
