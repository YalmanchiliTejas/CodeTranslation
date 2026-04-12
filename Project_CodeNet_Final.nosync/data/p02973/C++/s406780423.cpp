#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,ans,L;
vector<ll> v;
int main(void){
    cin>>n;
    for(int i=0;i<=100000;i++)v.push_back(-1);
    for(int i=0;i<n;i++){
        cin>>a;
        L=lower_bound(v.begin(),v.end(),a)-v.begin();
        v[L-1]=a;
    }
    for(auto x:v)if(x!=-1)ans++;
    cout<<ans<<endl;
}
