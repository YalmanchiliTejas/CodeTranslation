#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++) 

int main() {
int n; cin>>n;
int mx = 0;
int ans = 0;
f(i,0,n) {
int x; cin>>x;
mx = max(x,mx);
if (mx <= x) ans++;
}
cout << ans << endl;
return 0;
}