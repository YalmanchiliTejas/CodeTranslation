#include <bits/stdc++.h>
#define ll long long

using namespace  std;

int n,k;
ll res;

int main() {
    cin>>n>>k;
    if (k==0) cout<<1ll*n*n;
    else {
        for (int b=k+1;b<=n;b++) res+=(b-k)*(n/b) + max(n%b-k+1,0);
        cout<<res;
    }
}
