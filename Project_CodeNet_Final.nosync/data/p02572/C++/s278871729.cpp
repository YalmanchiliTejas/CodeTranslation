#include<bits/stdc++.h>
using namespace std;
//void dfs(unordered_map<int,unordered_set<int>>&m,int st)
 int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long int t;
    int mod=1000000007;

    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int pa[n];
    long long int c=0;
    for(int i=0;i<n;i++)
    {
        c+=a[i];
        pa[i]=c;
    }
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        long long int ff=(c-pa[i])%mod;
        long long int ss=(a[i]*ff)%mod;
        ans=(ans+ss)%mod;
    }
    cout<<ans<<endl;

}