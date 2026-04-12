#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a.at(i);
    sort(all(a));
    if(n%2==0){
        int tmp=0;
        rep(i,n){
            if(i<n/2-1)tmp-=a.at(i)*2;
            else if(i==n/2-1)tmp-=a.at(i);
            else if(i==n/2)tmp+=a.at(i);
            else tmp+=a.at(i)*2;
        }
        cout<<tmp<<endl;
    }else{
        int tmp=0;
        rep(i,n){
            if(i<=n/2-2)tmp-=a.at(i)*2;
            else if(i<=n/2)tmp-=a.at(i);
            else tmp+=a.at(i)*2;
        }
        int tmp2=0;
        rep(i,n){
            if(i<n/2)tmp2-=a.at(i)*2;
            else if(i<n/2+2)tmp2+=a.at(i);
            else tmp2+=a.at(i)*2;
        }
        cout<<max(tmp,tmp2)<<endl;
    }
}