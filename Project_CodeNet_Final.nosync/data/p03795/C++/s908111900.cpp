#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = n*800;
    while(n >=15) {
        n-=15;
        ans-=200;
    }
    cout << ans << endl;
}