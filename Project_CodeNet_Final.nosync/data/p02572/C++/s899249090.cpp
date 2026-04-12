#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll A[200001];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];

    vector<ll> sum(N+1);
    repn(i,N){
        sum[i]+=sum[i-1]+A[i];
        sum[i]%=MOD;
    }

    ll ans=0;
    repn(i,N){
        ans+=A[i]*(sum[N]-sum[i]);
        ans%=MOD;
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}