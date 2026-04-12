#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
ll vis[100005]={0};
ll par[100005]={0};
//map<ll,ll> mp;
ll ma=0;
void dfs(vector<ll> v1[],int x)
{
    
    vis[x]=1;
        for(auto i : v1[x])
        {
            if(vis[i]==0)
                dfs(v1,i);
        }
        
    return ;
}*/
int main()
{
    ll a,b,c,d,e,x,t,n,m,count;
    //ll ma=-1;
    t=1;
    //cin>>t;
    string s1;
    //vector<ll> ev,od;
    //map<char,ll> mp;
    set <char> se;
    while(t--)
    {
        
        cin>>s1;
        for(int i=0;i<s1.size();i++)
        {
            se.insert(s1[i]);
        }
        if(se.size()==2) cout<<"Yes";
        else cout<<"No";
        
        
    }
    return 0;
}
 