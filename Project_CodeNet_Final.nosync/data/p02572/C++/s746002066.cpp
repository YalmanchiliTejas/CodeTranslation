#include<bits/stdc++.h>
#define pb push_back
#define int long long int
const int mod=1e9+7;
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n; cin>>n;
    int v[n], p[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int s=0;
    for(int i=n-1; i >=0; i--){
        s =(s+v[i])%mod;

        p[i]=s;
    }
    int q=0;
    for(int i=0; i<n-1; i++){
        q =(q+((v[i]*(p[i+1]))%mod))%mod;
    }
    cout<<q<<endl;
}