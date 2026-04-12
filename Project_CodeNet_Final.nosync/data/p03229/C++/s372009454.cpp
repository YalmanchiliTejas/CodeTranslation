#include <bits/stdc++.h>
using namespace std;

#define p(i,a,b) for(int i=a;i<b;++i)

int main(){
    int n,b;
    cin >> n;
    b = n/2;
    vector<int> a(n);
    p(i,0,n) cin >> a[i];
    sort(a.begin(),a.end());
    int64_t s = a[n-1] - a[0];
    p(i,1,b) s += a[n - i] - a[i] + a[n-i-1] - a[i-1];
    if(n & 1) s += max(a[b] - a[b - 1],a[b+1] - a[b]);
    cout << s << '\n';
}