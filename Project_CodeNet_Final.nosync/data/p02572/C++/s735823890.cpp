#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const ll MOD=1e9+7;

int main(){
    int N; cin >> N;
    ll a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    ll sum=0;
    for(int i=0;i<N;i++){
        sum+=a[i];
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        sum-=a[i];
        ans+=(a[i]%MOD)*(sum%MOD)%MOD;
        ans%=MOD;
    }
    cout << ans << endl;
}