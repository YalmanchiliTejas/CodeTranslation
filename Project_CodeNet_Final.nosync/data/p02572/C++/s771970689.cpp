#include <bits/stdc++.h>
#define ll unsigned long long
#define ALL(x) x.begin(),x.end()
#define MOD (1000000000+7)
using namespace std;
#define PI 3.14159265359
#define tMOD 998244353
#define mkpr(x,y) make_pair(x,y)



int main(){
ll N;
cin>>N;
vector<ll> A(N);

for(ll i=0;i<N;i++){
    cin>>A[i];
}

vector<ll> wa(N+1);
wa[0]=0;
for(ll i=0;i<N;i++){
    wa[i+1]=wa[i]+A[i];
}
ll ans=0;
for(ll i=0;i<N-1;i++){
ans+= (A[i]*((wa[N]-wa[1+i])%MOD)%MOD);
ans%=MOD;

}

cout<<ans%MOD<<endl;





}









