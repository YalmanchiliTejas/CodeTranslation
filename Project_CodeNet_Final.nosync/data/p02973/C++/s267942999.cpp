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

int b(int a,vector<int> &v){
    int l=0,r=v.size()-1,ce;
    while(l!=r){
        ce=(l+r+1)/2;
        if(v[ce]<a) l=ce;
        else r=ce-1;
    }
    return l;
}

int main() {
    int n,cnt=0; cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    vector<int> color(n,-1);
    rep(i,n){
        int ch=b(a[i],color);
        if(color[ch]==-1) cnt++;
        color[ch]=a[i];
    }
    cout<<cnt<<endl;
}