#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 10000000
#define ll long long
using namespace std;

int main(){
    ll n; cin>>n;
    vector<ll> que;
    ll a; cin>>a; que.push_back(a);
    ll count=1;
    for(ll i=0; i<n-1; i++){
        ll x; cin>>x;
        if(x>que.back()){
            que.back()=x;
            continue;
        }
        
        if(x<=que.front()){
            que.insert(que.begin(),x);
            count++;
            continue;
        }
        
        auto it=lower_bound(que.begin(),que.end(),x);
        ll index=it-que.begin();
        que[index-1]=x;
    }
    
    cout<<count<<endl;
}