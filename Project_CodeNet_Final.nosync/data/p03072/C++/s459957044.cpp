#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define ll long long

int main(){
    int n,h[25];
    cin>>n;
    rep(i,n) cin>>h[i];
    int count=0;
    rep(i,n){
        int a=1;
        rep(j,i+1){
            if(h[i]<h[j]) a=0;
        }
        if(a) count++;
    }
    cout<<count<<endl;
}