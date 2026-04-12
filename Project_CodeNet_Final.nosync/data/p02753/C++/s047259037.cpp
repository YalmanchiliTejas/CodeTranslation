// Author :mastermindevil/mdragneell
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
#define endl '\n'
 
 
ll const mod=1e9+7;
ll const N=1e5+5;
ll fact[N];
ll min(ll x,ll y) { if(x < y) return x; else return y; }
ll max(ll x,ll y) { if(x > y) return x; else return y; }
ll gcd(ll x,ll y) { if(x == 0) return (y>0?y:1); else return gcd(y%x,x);}
ll powmod(ll x,ll y){ll res=1;while(y>0){if(y%2==1)res=(res*x)%mod;y>>=1;if(y<=0)break;x=(x*x)%mod;}return res;}
ll factorial () { fact[0]=1; fact[1]=1; for(int i=2;i<N;i++) fact[i]=(fact[i-1]*i)%mod;}ll
 
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);}
    size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);}
};
struct compare {
    bool operator()(const pair<ll, ll>& value,  const ll& key){ return (value.first < key); }
    bool operator()(const ll& key, const pair<ll, ll>& value) { return (key < value.first); }
};
 
bool compare1(const pair<ll,ll> &a,const pair<ll,ll> &b)
{   
    if(a.f==b.f)
    {
        if(a.s<=0 && b.s<=0) return (a.s>b.s);
        return (a.s<b.s);
    }
    else if(a.f<=0 && b.f<=0 ) return (a.f > b.f);
    else return (a.f<b.f);
}


int main()
{

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        

        string s;
        cin>>s;

        if(count(s.begin(),s.end(),'A')==3)
            cout<<"No"<<endl;
        else if(count(s.begin(),s.end(),'C')==3)
            cout<<"No"<<endl;
        else if(count(s.begin(),s.end(),'B')==3)
            cout<<"No"<<endl;
        
        else
            cout<<"Yes"<<endl;

}