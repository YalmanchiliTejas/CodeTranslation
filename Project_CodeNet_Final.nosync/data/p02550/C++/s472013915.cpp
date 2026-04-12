#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
ll n;
ll k,m,x;
ll a[N];
int b[N];
int ans[N];
string s;
int vis[N];
map<ll,int> mp;
int used[25];
int cmp(int a, int b){
    return a>b;
}
ll dp[N];
ll pre[N];


int main()
{
    cin>>n>>x>>m;
    a[1]=x;
    mp[x]=1;
    ll xunhuan=0;
    ll sum=x;
    for(int i=2;i<=n;i++){
        a[i]=(a[i-1]*a[i-1])%m;
        if(mp[a[i]]){
            xunhuan=i;
            break;
        }
        mp[a[i]]=i;
        sum+=a[i];
    }
    //int ans=0;
    if(xunhuan==0){
        cout<<sum<<endl;
    }
    else{
        //cout<<xunhuan<<endl;
        ll start=mp[a[xunhuan]];
        ll endd=xunhuan-1;
        ll xsum=0;
        ll jie=endd-start+1;
        //cout<<a[789]<<endl;
        for(ll i=start;i<=endd;i++){
            xsum+=a[i];
        }
        ll le=n-endd;
        ll num=le/jie;
        ll shengyu=le%jie;
        sum=sum+num*xsum;
        for(ll i=start;i<=endd;i++){
            if(shengyu==0) break;
            sum+=a[i];
            shengyu--;
            if(shengyu==0) break;
        }
        cout<<sum<<endl;


    }


}

