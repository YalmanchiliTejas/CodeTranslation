#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll prime[N],k,t,n;
bool isprime[N];
void Prime(){
    fill(isprime,isprime+N,1);
    k=0;
    prime[1]=0;
    for(ll i=2;i<N;i++){
        if(isprime[i]){
            prime[k++]=i;
            for(ll j=2;i*j<N;j++)
                isprime[i*j]=0;
        }
    }
}

ll solve(ll n){
    ll cnt=0,ans=0;
    for(ll i=0;i<k&&prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            cnt=0;
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }
            ans?ans=__gcd(ans,cnt):ans=cnt;
        }
    }
    if(n>1) ans?ans=__gcd(ans,n):ans=1;
    return ans;
}

int main(){
  int x;cin>>x;
  if(x>=30) puts("Yes");
  else puts("No");
}
