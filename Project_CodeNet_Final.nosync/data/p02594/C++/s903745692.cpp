// By Debajit Chakraborty
#include<bits/stdc++.h>
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MP make_pair
#define pb push_back
#define ff first
#define ss second
#define sz(x) x.size()
#define all(c) c.begin(),c.end()
#define int long long
#define fr(i,j,x) for(int i=j;i<x;i++)
#define rep(i,j,x) for(int i=j;i<=x;i++)
#define rev(i,j,x) for(int i=j;i>=x;i--)
#define mem(x,val) memset(x,val,sizeof(x))
//#define endl '\n'
#define vi vector<int>
#define pii pair<int,int>
 
const int mod=1e9+7;
const int N=2e5+10;
const int INF=1e12;



void solve(){
    int x;
    cin>>x;
    if(x>=30){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}


int32_t main()
{
    
    SPEED;
    int T=1;
    //cin>>T;
    int t1=1;
    while(true)
    {  
        //cout<<"Case #"<<t1<<": ";
        //cout<<endl;
        solve();
        t1++;
        if(t1>T)
            break;
    }
}   
