#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;



int main() {
int H,W;
cin>>H>>W;
char A[H][W];
bool bl_r[H],bl_c[W];
rep(i,H){
    bl_r[i]=false;
}
rep(i,W){
    bl_c[i]=false;
}
rep(i,H){
    rep(j,W){
        cin>>A[i][j];
        if(A[i][j]=='#'){
            bl_r[i]=true;
            bl_c[j]=true;
        }

    }
}
rep(i,H){
    if(bl_r[i]){
    rep(j,W){
        if(bl_c[j]){
        cout<<A[i][j];

        }
        
    }
    cout<<endl;
    }
}
return 0;
}