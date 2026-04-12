
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
int n;
int a[maxn], b[maxn];

void input() {
cin>>n;
}

void solve() {

    if(n>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}




int main() {
    std::ios::sync_with_stdio(false);
    int test = 1;
    while (test--) {
        input();
        solve();
    }
    return 0;
}
