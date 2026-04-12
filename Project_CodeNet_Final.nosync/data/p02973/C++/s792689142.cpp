#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
const int MOD=1e9+7;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b;
    b.push_back(a[n-1]);
    invrep(i,n-1) {
        int j=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        if (j==b.size()) b.push_back(a[i]);
        else b[j]=a[i];
    }
    cout << b.size() << endl;
}