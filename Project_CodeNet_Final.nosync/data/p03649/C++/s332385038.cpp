#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAX=200050;
ll n,a[MAX],k,min_a=(1ll<<63)-1ll,cut;
priority_queue<ll> mtry;
int main(){
    scanf("%lld",&n);
    cut=n;
    for(int i=0;i<n;i++) scanf("%lld",&a[i]),min_a=min(a[i],min_a);
    for(int i=0;i<n;i++){
        ll t=(a[i]-min_a)/(n+1);
        a[i]-=t*(n+1); k+=t;
    }
    for(int i=0;i<n;i++) a[i]+=k;
    ll t=max(min_a+k-n,0ll);
    for(int i=0;i<n;i++) k+=t, a[i]-=t;
    for(int i=0;i<n;i++) mtry.push(a[i]);
    while(mtry.top()>=cut){
        ll t=mtry.top();
        mtry.pop(), t-=(n+1); mtry.push(t);
        cut--; k++;
    }
    printf("%lld\n",k);
}
