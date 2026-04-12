#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i< int (n); i++)
using namespace std;
typedef long long ll;

int main(){

ll ans=0;
int n;
cin >> n;
vector<ll> a(200100);
rep(i,n) cin >> a[i];

ll sum=0, b=0, diag=0, c=0;
for(int i=0; i<n; i++) b = (b+a[i])%1000000007;
for(int i=0; i<n; i++) diag = (diag+(a[i]*a[i])%1000000007)%1000000007;
sum = (b*b)%1000000007;
c=(sum-diag+1000000007)%1000000007;
if(c%2==0) ans=c/2;
else ans = (c+1000000007)/2;

cout << ans << endl;


/*
for(int j=0; j<n; j++){
    for(int i=0; i<j; i++){
        ans = (ans + (a[i]*a[j])%1000000007)%1000000007;
    }
}
*/

}