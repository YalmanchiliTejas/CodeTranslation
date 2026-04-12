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
#include <iomanip>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define queint queue<int>
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
    int n=in(),m=in();
    vec a(n-1);
    rep(i,n-1)a[i]=i+1;
    vector<vector<bool>> bl(n,vector<bool>(n));
    rep(i,m){
        int x=in()-1,y=in()-1;
        bl[y][x]=bl[x][y]=true;
    }
    int ans=0;
    do{
        bool flag=true;
        if(!bl[0][a[0]])flag=false;
        rep(i,n-2)if(!bl[a[i]][a[i+1]])flag=false;
        if(flag)ans++;
    }while(next_permutation(All(a)));
    cout<<ans<<endl;
}
