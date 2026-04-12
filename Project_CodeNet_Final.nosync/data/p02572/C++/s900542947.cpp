#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll
#define MOD (1000*1000*1000+7)

int t, n, m, k, a[300010], q, l, r;

int32_t main(){
INIT
cin>>n;
int sum=0;
int pr=0;
for(int i=1; i<=n; i++){
    cin>>a[i];
}
for(int i=n; i>=1; i--){
    pr=(pr+(sum*a[i])%MOD)%MOD;
    sum=(sum+a[i])%MOD;
}
cout<<pr;


return 0;
}



