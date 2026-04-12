#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    if(N % 2 == 1) {
        int cnt = 1;
        ll ret = 0;
        for(int i = 0;i < N / 2;i++) {
            ret += vec.at(cnt);
            cnt += 2;
        }
        cnt = 1;
        vector<ll> left(N / 2 + 1);
        vector<ll> right(N / 2 + 1);
        for(int i = 0;i < N / 2;i++) {
            left.at(i + 1) = left.at(i) + (vec.at(cnt - 1) - vec.at(cnt));
            cnt += 2;
        }
        cnt = N - 2;
        for(int i = 0;i < N / 2;i++) {
            right.at(i + 1) = right.at(i) + (vec.at(cnt + 1) - vec.at(cnt));
            cnt -= 2;
        }
        ll cnt2 = 0;
        ll Max = 0;
        for(int i = N / 2;i >= 0;i--) {
            Max = max(Max,right.at(N / 2 - i));
            cnt2 = max(cnt2,Max + left.at(i));
        }
        cout << ret + cnt2 << endl;
    }
    else {
        int cnt = 1;
        ll ret = 0;
        for(int i = 0;i < N / 2;i++) {
            ret += vec.at(cnt);
            cnt += 2;
        }
        cnt = 1;
        vector<ll> left(N / 2 + 1);
        for(int i = 0;i < N / 2;i++) {
            left.at(i + 1) = left.at(i) + (vec.at(cnt - 1) - vec.at(cnt));
            cnt += 2;
        }
        ll cnt2 = 0;
        for(int i = N / 2;i >= 0;i--) {
            cnt2 = max(cnt2,left.at(i));
        }
        cout << ret + cnt2 << endl;
    }
}