#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#ifdef _DEBUG_
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl
#else
#define dump(val)
#endif

using namespace std;

typedef long long int ll;
typedef pair<ll, string> P;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

bool cmp(const P &p1, const P &p2) {
    if (p1.first != p2.first) {
        return p1.first > p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, K, L;
    while (cin >> N >> M >> K >> L, N) {

        vector<P> anime(N);
        vector<P> fav(M);
        {
            map<string, ll> mp;
            REP(i, 0, N) {
                cin >> anime[i].second >> anime[i].first;
                mp[anime[i].second] = anime[i].first;
            }

            REP(i, 0, M) {
                cin >> fav[i].second;
                fav[i].first = mp[fav[i].second];
            }
        }
        sort(anime.begin(), anime.end(), cmp);
        sort(fav.begin(), fav.end(), cmp);
        if (N == K) {
            cout << M << endl;
            continue;
        }

        int l = 0, r = min(K, M);
        int ans = 0;
        while (l <= r) {
            auto cp = anime;
            int mid = (l + r) / 2;
            ll sum = 0;
            REP (i, 0, mid) {
                int p1 = i, p2 = K - mid + i;
                if (cmp(cp[p2], fav[p1])) {
                    sum += cp[p2].first - fav[p1].first;
                    sum += (cp[p2].second < fav[p1].second);
                    swap(cp[p2], cp[p2 + 1]);
                } 
            }
            if (sum <= L) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

