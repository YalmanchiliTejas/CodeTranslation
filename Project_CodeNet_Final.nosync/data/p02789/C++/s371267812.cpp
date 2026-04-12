// Author :mdragneell
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

 
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define pl  pair< ll,ll >
#define f first
#define s second
 
ll const N=1e5+5;
ll const mod=1e9+7;
ll min(ll x,ll y) { if(x < y) return x; else return y; }
ll max(ll x,ll y) { if(x > y) return x; else return y; }
ll gcd(ll x,ll y) { if(x == 0) return y; else return gcd(y%x,x);}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
       
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct compare { 
    bool operator()(const pair<ll, ll>& value,  
                                const ll& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const ll& key,  
                    const pair<ll, ll>& value) 
    { 
        return (key < value.first); 
    } 
}; 

bool compare1(const pair<ll,ll> &a, 
            const pair<ll,ll> &b) 
{ 
    if(a.first<b.first) 
        return true ;
    else if(a.first==b.first) 
        return (a.second > b.second); 
    else return false;
} 

ll powmod(ll x, ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)
            res=(res*x)%mod;
        y>>=1;
        if(y<=0)
            break;

        x=(x*x)%mod;
    }

    return res;
}


int main()
{
 
 
       ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
       /* #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif */


        ll tt=1;
        //cin>>tt;

        while(tt--)
        {
            ll n,m;
            cin>>n>>m;


            if(n==m)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;







        }  
 
}