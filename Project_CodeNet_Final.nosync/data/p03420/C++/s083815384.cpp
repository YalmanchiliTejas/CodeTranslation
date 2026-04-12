#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdio>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>()>
#define pb push_back
#define vec vector<int>
#define vecvec vector<vector<int>>
#define vecll vector<ll>
#define vecvecll vector<vector<ll>>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
#define mp make_pair
using namespace std;
int in(){int x;scanf("%d",&x);return x;}
string stin(){string s;cin>>s;return s;}
ll lin(){ll x;scanf("%lld",&x);return x;}
int main(){
    ll n=in(),k=in();
    ll ans=0;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    rep2(b,k+1,n){
        ans+=n/b*(b-k)+max(0ll,n%b-k+1);
    }
    cout<<ans<<endl;
}
