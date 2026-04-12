#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  loop(i,0,n)
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define vi vector<int>
#define vl vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>

int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];

    int ans=0;
    rep(i,n){
        int flag=0;
        for(int j=0;j<i;j++){
            if(a[i]<a[j])flag=1;
        }
        if(flag==0)ans++;
    }

    cout<<ans<<endl;
}