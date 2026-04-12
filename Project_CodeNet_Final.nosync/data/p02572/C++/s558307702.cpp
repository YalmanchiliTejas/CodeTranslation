#include<bits/stdc++.h>
using namespace std;
const int mx=1e9+7;

#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>pre;
    for(int &i:v)
        cin>>i;
    pre.push_back(v[0]);
    for(int i=1;i<n;i++)
        pre.push_back(pre[pre.size()-1]+v[i]);
    int ans=0;
    for(int i=0;i<n-1;i++){
        int p=((v[i]%mx*(pre[n-1]%mx-pre[i]%mx+mx)%mx)%mx)%mx;
        ans=(ans%mx+p%mx)%mx;
    }
    cout<<ans<<endl;
}


signed main()
{
    int t;
    solve();
}