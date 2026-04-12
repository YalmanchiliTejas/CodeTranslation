#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    if(N % 2 == 0) {
        ll ret = 0;
        for(int i = 0;i < N;i++) {
            if(i < N / 2 - 1) {
                ret += vec.at(i) * 2;
            }
            else if(i == N / 2 - 1) {
                ret += vec.at(i);
            }
            else if(i == N / 2) {
                ret -= vec.at(i);
            }
            else {
                ret -= vec.at(i) * 2;
            }
        }
        cout << ret << endl;
    }
    else {
        ll ret1 = 0;
        ll ret2 = 0;
        for(int i = 0;i < N;i++) {
            if(i < N / 2 - 1) {
                ret1 += vec.at(i) * 2;
            }
            else if(i == N / 2 - 1 || i == N / 2) {
                ret1 += vec.at(i);
            }
            else {
                ret1 -= vec.at(i) * 2;
            }
        }
        for(int i = 0;i < N;i++) {
            if(i < N / 2) {
                ret2 += vec.at(i) * 2;
            }
            else if(i == N / 2 || i == N / 2 + 1) {
                ret2 -= vec.at(i);
            }
            else {
                ret2 -= vec.at(i) * 2;
            }
        }
        cout << max(ret1,ret2) << endl;
    }
}