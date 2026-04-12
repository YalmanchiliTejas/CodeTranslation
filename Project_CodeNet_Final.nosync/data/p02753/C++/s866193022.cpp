#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include<bits/stdc++.h>
#include <iostream>
#include<algorithm>
#include<list>
#include <functional>
#include <map>
#include <deque>
using namespace std;

#define pt(...) prllf(__VA_ARGS__)
#define sf(...) scanf(__VA_ARGS__)
#define fui(p,n,d) for(ll i = p;i <= n; i += d)
#define fut(p,n,d) for(ll t = p;t <= n; t += d)
#define fuj(p,n,d) for(ll j = p;j <= n; j += d)
#define fdi(n,p,d) for(ll i = n;i >= p; i -= d)
#define fdt(n,p,d) for(ll t = n;t >= p; t -= d)
#define fdj(n,p,d) for(ll j = n;j >= p; j -= d)
#define Conn(x,y) x##y
#define ToString(x) #x
#define ll long long
#define MOD 1000000007
#define p(a,b) pow((double)a, b)
#define me(a,b) memset(a,b,sizeof(a))
bool compare(ll a, ll b){return a>b;}

string s;

int main(){
    cin>>s;
    int a[2];
    me(a,0);
    fui(0,2,1){
        if(s[i] == 'A') a[0]++;
        else a[1]++;
    }
    if(a[0] == 2 || a[1] == 2) cout<<"Yes";
    else cout<<"No";

    return 0;
}

