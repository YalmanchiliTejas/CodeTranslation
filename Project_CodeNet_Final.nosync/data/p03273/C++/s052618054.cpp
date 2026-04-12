#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
#define MOD 1000000007
using ll = long long;
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int h,w;
cin>>h>>w;
vector<vector<char>> a(h,vector<char>(w));
set<int> use_i,use_j;

rep(i,h){
    rep(j,w){
        cin>>a[i][j];
        if(a[i][j]=='#'){
            use_i.insert(i);
            use_j.insert(j);
        }
    }
}
rep(i,h){
    bool out=false;
    rep(j,w){
        if(use_i.count(i)&&use_j.count(j)){
            cout<<a[i][j];
            out = true;
        }
    }
    if(out)cout<<endl;
}
//system("pause");
return 0;
}