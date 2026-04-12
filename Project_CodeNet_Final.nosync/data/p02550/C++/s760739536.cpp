#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 1000000007
#define ll long long
using namespace std;

int main(){
    ll n,x,m; cin>>n>>x>>m;
    map<ll,int> mp;
    ll pos=x;
    ll count=1;
    ll sum_=x;
    ll rec=-1;
    vector<ll> vec;
    while(true){
        pos=pow(pos,2);
        pos=pos%m;
        sum_+=pos;
        count++;
        mp[pos]++;
        if(count==n){
            cout<<sum_<<endl;
            return 0;
        }
        if(mp[pos]==2){ 
            vec.push_back(pos);
            if(rec==-1) rec=count-1;
        }
        if(mp[pos]==3) break;
    }
    
    ll sumsum=0;
    for(ll i=0; i<vec.size(); i++) sumsum+=vec[i];
    rec-=vec.size();
    
    pos=x;
    ll ans=x;
    for(ll i=1; i<rec; i++){
        pos=pow(pos,2);
        pos=pos%m;
        ans+=pos;
    }
    //cout<<ans<<endl;
    ll p=n-rec;
    p/=vec.size();
    ll q=n-rec-p*vec.size();
    
    ans+=sumsum*p;
    
    for(ll i=0; i<q; i++){
        ans+=vec[i];
    }
    
    //cout<<p<<endl;
    cout<<ans<<endl;
}