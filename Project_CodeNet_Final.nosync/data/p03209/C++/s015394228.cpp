#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll burger(ll N,ll X);
ll a[55],p[55];

int main(){
    ll N,X;
    cin>>N>>X;
    a[0]=1;
    p[0]=1;
    for(int i=0;i<N;i++){
        a[i+1]= a[i]*2 + 3;
        p[i+1]= p[i]*2 + 1;
        //cout<<"a["<<i<<"]"<<a[i]<<endl;
        //cout<<"p["<<i<<"]"<<p[i]<<endl;
    }
    cout<<burger(N,X)<<endl;
    return 0;
}
ll burger(ll N, ll X){
    if(N==0){
        return X;
    }
    else{
        //cout<<"a["<<N-1<<"]="<<a[N-1]<<endl;
        //cout<<"X="<<X<<endl;
        if(X==1){ return 0; }
        else if(X <= (1 + a[N-1])){ return burger(N-1,X-1); }
        else if(X == (2 + a[N-1])){  return 1+burger(N-1,a[N-1]); }
        else if(X <= (2 + 2*a[N-1])){  return burger(N-1,a[N-1]) + 1 + burger(N-1,X-2-a[N-1]); }
        else if(X == (3 + 2*a[N-1])){  return 1+2*burger(N-1,a[N-1]); }
    }
    return -1;
}