#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    ll x = 800 * N;
    ll y = (ll)(N / 15) * 200;
    cout << x - y << endl;
    return 0;
}