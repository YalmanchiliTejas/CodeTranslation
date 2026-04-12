#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n;
    int k;
    cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    ll res=0;
    for(int b=k+1;b<=n;b++){
        ll shuki=(n+1)/b;
        ll par=b-k;
        ll rest=n%b-k+1;
        if(rest<0 || (n+1)%b==0) rest=0;
        res+=par*shuki+rest;
    }
    cout<<res<<endl;
    
    return 0;
}