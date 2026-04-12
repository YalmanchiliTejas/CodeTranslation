#include<bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run ios_base::sync_with_stdio(false);cin.tie(NULL);
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll,ll>
#define shunno cout<<0<<endl;
#define pi 2*acos(0.0)1
#define hobena cout<<-1<<endl;








void oka()
{
        ll n,i,j,k,sum=0,mod=1e9+7;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i],sum+=a[i];
        ll ans=0;
        for(i=0;i<n;i++)
        {
            sum-=a[i];
            ans+=((a[i]%mod)*(sum%mod))%mod;
            ans%=mod;
        }
        cout<<ans<<endl;





}






int main()
{
   //string g="abcd";
    //g.erase(g.begin()+3);
    //cout<<g<<endl;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    run
    ll i,t;
    t=1;
   //cin>>t;


    for(i=1;i<=t;i++)
    {


    oka();
    }






}
