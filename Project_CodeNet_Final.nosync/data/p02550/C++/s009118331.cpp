#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> exist(100003, -1);
    vector<ll> totals(100003, 0);
    ll iterate = 1;
    ll total = 0;
    ll a = X;
    bool loop_done = false;
    while (iterate <= N) {
        total = total + a;
        if (!loop_done) {
            if (exist[a] > 0) {
                ll loop_iter = iterate - exist[a];
                ll loop_sum = totals[iterate - 1] - totals[exist[a] - 1];
                ll loop_num = max(N / loop_iter - 3, 0L);
                total = total + loop_num * loop_sum;
                iterate = iterate + (loop_num * loop_iter);
                loop_done = true;
            } else {
                totals[iterate] = total;
                exist[a] = iterate;
            }
        }
        a = (a * a) % M;
        iterate++;
    }
    print(total);
}
