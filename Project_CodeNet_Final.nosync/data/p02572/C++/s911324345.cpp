#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll M=1e9+7;
ll a[200005], sum, n, ps[200005];
int main() {
   cin >> n;
   for (int i=0; i<n; i++) cin >> a[i];
   
   ps[n-1]=a[n-1];
   sum=(sum+(a[n-2]%M)*(ps[n-1]%M))%M;
   for (int i=n-2; i>=0; i--) {
       ps[i]=ps[i+1]+a[i];
       sum=(sum+(a[i-1]%M)*(ps[i]%M))%M;
    }
   
   cout << sum;
}