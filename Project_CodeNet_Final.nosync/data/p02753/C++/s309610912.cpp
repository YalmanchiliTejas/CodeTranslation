#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define bug(x) cerr<<#x<<"="<<x<<endl;
#define el printf("\n");
const ll mod = 1e7;




inline ll nxt() {
	ll x;
	scanf("%lld\n",&x);
	return x;
}
inline void print(int n){
    printf("%d ",n);
}


ll nCr(ll n ,ll k){
    if( k==n || k==0 )return 1;
    return (nCr(n-1,k-1)%mod+nCr(n-1,k)%mod)%mod;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    if(s=="AAA"||s=="BBB")printf("No\n");
    else printf("Yes\n");



}
