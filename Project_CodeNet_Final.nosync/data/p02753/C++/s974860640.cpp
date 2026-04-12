//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define de_x(x) cout<< #x <<"->debug_val: "<<x<<endl;
#define de_ve(x) for(auto it: x) cout<<it<<" ";
#define rep(i,a,n) for (int i=a;i<n;i++)
#define _rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
//std::mt19937 mrand(random_device{}());
//int rnd(int x) { return mrand() % x ; }
const ll mod=1e7;
ll ksm(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int _,n,m;
/***********************/
void run(){
}
int main(){
//    for(scanf("%d",&_);_;_--) run();
    string s;
    getline(cin,s);
    int a =0,b=0;
    rep(i,0,s.size()){
        if(s[i] =='A') a++;
        else b++;
    }
    if(a >0 && b> 0) puts("Yes");
    else puts("No");
    return 0;
}