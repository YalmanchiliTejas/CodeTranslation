#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main() {
    int n,sum=1,maxi;
    cin>>n;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    maxi=h[0];
    for (int i=1; i<n; i++) {
        if (maxi<=h[i]) {
            sum++;
            maxi=h[i];
        }
    }
    cout<<sum<<endl;
}