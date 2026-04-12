#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
#define foR for

// FHCまでにスタックオーバーフローの罠を解決する


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);


    ll n;cin>>n;
    if(n >= 30)cout << "Yes\n";
    else cout << "No\n";
}