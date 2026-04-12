#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;


int main(){
    int x,y,z;cin>>x>>y>>z;
    x-=z;
    int ans=x/(y+z);
    cout <<ans <<endl;
    return 0;
}