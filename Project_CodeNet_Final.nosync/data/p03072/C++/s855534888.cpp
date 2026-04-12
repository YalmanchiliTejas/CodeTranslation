#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define P pair<int,int>
#define prique priority_queue
int n,h[40],minv=0,ans=0;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>h[i];
        if(minv<=h[i]){
            ans++;
            minv=h[i];
        }
    }
    cout<<ans<<endl;
}
