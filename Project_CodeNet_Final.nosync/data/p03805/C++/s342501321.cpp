#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,L,v[9][9],ans,a,b,cnt;
vector<ll> u;
int main(void){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        v[a][b]=1;;
        v[b][a]=1;
    }
    for(int i=2;i<=n;i++){
        u.push_back(i);
    }
    do{
        L=1;
        cnt=0;
        for(auto x:u){
            if(v[L][x]==1)cnt++;
            L=x;
        }
        if(cnt==n-1)ans++;
    }while(next_permutation(u.begin(),u.end()));
    cout<<ans<<endl;
}
