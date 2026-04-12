#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n;
    cin>>n;
    ll h[25];
    for(int i=0;i<n;i++)cin>>h[i];
    ll count=1,max_h=h[0];
    for(int i=1;i<n;i++){
        if(h[i]>=max_h){
            count++;
            max_h=h[i];
        }
    }
    cout<<count<<endl;
}