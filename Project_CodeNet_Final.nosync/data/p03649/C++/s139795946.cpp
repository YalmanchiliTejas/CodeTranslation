#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<random>
#include<stdio.h>
using namespace std;

typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<ll> a(N);
    for (int i=0;i<N;i++){
        cin>>a[i];
    }

    vector<ll> data(N+1);
    ll ans=0;
    ll q=0;
    for (int i=0;i<N;i++){
        q+=(a[i]+1)/(N+1);
        data[(a[i]+1)%(N+1)]+=1;
    }
    ans=q*(N+1);

    for (ll r=1;r<N+1;r++){
        q+=data[N+1-r]-1;
        ll t=0;
      	ll zero=0;
        t=std::max(q,zero)*(N+1)+r;
        ans=std::min(ans,t);
    }
    cout<<ans<<endl;
}