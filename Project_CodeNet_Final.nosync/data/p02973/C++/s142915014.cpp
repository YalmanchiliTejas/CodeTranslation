#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1 << 30;

using namespace std;

using ll = long long;
using P = tuple<int, int>;
using iarr = valarray<int>;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    deque<int> d;
    for(int i= 0; i < N; ++i) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (p == 0){
            d.push_front(a[i]);
        }else {
            d[p-1] = a[i];
        }
    }

    cout << d.size() << endl;
    return 0;
}

