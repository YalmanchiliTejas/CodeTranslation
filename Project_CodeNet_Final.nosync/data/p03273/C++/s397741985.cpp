//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    int h,w; cin>>h>>w;
    vector<int> hl(h,0),wl(w,0);
    vector<vector<char>> m(h,vector<char>(w,'q'));
    rep(i,h){
        rep(j,w){
            cin>>m[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            if(m[i][j]=='.') hl[i]++;
        }
    }
    rep(i,w){
        rep(j,h){
            if(m[j][i]=='.') wl[i]++;
        }
    }
    rep(i,h){
        if(hl[i]==w) continue;
        rep(j,w){
            if(wl[j]==h) continue;
            cout<<m[i][j];
        }
        cout<<endl;
    }
}