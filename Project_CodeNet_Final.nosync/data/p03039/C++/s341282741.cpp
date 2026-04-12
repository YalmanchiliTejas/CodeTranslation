#include <iostream>
using namespace std;
typedef long long ll;
ll M=1e9+7, Mf[200002];
void Mfi(){
    Mf[0]=Mf[1]=1;
    for(int i=2;i<200002;i++)Mf[i]=(Mf[i-1]*i)%M;
}
ll Mp(ll a, ll b){
    if(b==0)return 1;
    else if(b%2==0)return Mp((a*a)%M, b/2)%M;
    return (a*Mp(a, b-1))%M;
}
ll Mc(ll a, ll b){
    if(a<b)return 0;
    ll c = (Mf[a]*Mp(Mf[a-b], M-2))%M;
    return (c*Mp(Mf[b], M-2))%M;
}
int main(void){
    ll n, m, k, u=0, t;
    cin >> n >> m >> k;
    Mfi();
    t = Mc(n*m-2, k-2);
    for(ll i=1;i<n;i++){
        for(ll j=1;j<m;j++){
            u += (n-i)*(m-j)*(i+j);
            u %= M;
        }
    }
    u *= 2;
    for(ll i=1;i<n;i++){
        u += (n-i)*m*i;
        u %= M;
    }
    for(ll j=1;j<m;j++){
        u += n*(m-j)*j;
        u %= M;
    }
    cout << (t*u)%M <<endl;
}
