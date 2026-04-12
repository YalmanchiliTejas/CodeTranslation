//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,a,b) for(Int i=a;i<b;++i)
#define rrep(i,a,b) for(Int i=a;i>=b;--i)
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    cout << N*800 - (N/15)*200 << endl;
}
