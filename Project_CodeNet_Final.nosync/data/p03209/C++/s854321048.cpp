#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) obj.begin(),obj.end()
#define pb(obj) push_back(obj)
#define REP(i,N) for(ll i=0;i<N;i++)
typedef long long ll;
vector<ll>thick(51);
ll thickness(ll L){//レベルLの厚さ
    if(L==0)return thick[0]=1;
    if(thick[L]!=0)return thick[L];
    return thick[L]=thickness(L-1)*2+3;
}
ll num_of_P(ll L,ll n){//レベルL,下からn番目まで食べる時のパティの数
    if(L==0)return 1;
    if(n==1)return 0;
    else if(n<=1+thickness(L-1))return num_of_P(L-1,n-1);
    else if(n==2+thickness(L-1))return num_of_P(L-1,thickness(L-1))+1;
    else if(n<=2+2*thickness(L-1))return num_of_P(L-1,thickness(L-1))+1+num_of_P(L-1,n-2-thickness(L-1));
    else return 2*num_of_P(L-1,thickness(L-1))+1;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin>>N>>X;
    cout<<num_of_P(N,X)<<endl;
}