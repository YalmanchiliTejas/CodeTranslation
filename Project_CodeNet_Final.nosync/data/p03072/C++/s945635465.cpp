#include <iostream>
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    ll ans=0;
    ll maxH=0;
    for(int i=0;i<n;i++){
        if(h[i]>=maxH){
            ans+=1;
        }
        maxH=max(maxH,h[i]);
    }
    cout<<ans<<endl;
}