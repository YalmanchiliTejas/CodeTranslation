#include <bits/stdc++.h>
#include<math.h>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
using ll = long long;

int main(){
    ll N;
  	cin >> N;
    vector<ll> A(N);
    ll are=1000000007;
    ll sum=0;
    ll sum2=0;
    for(ll i=0; i<N; i++){
        cin >> A.at(i);
        sum+=A.at(i);
        if(sum>=are) sum-=are;
        ll b=A.at(i)*A.at(i);
        if(b>=are) b=b%are;
        sum2+=b;
        if(sum2>=are) sum2-=are; 
    }
    ll c=sum*sum;
    if(c>=are) c=c%are;
    ll d=c-sum2;
    if(d<0) d+=are;
    if(d%2!=0) d+=are;
    ll e=d/2;
    cout << e << endl;
}