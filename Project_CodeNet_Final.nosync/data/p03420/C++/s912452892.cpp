#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define mt make_tuple

ll n, k, ans=0;

int main(){
cin >> n >> k;
if(k==0)cout << 1LL*n*n << endl;
else {
rep(i, k+1, n){
    ll t = n/i;
ans+=1LL*(i-k)*(t);

if(n-t*i-k+1>0)ans+=n-t*i-k+1;

}
cout << ans << endl;

}

return 0;}
