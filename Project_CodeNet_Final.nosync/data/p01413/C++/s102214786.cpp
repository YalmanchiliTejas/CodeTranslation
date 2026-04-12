#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

struct Merchandice {
    string name;
    int weight;
    int price;

    Merchandice() {}
    Merchandice(const string &s, int w, int p) : name(s), weight(w), price(p) {}

};

struct Town {
    int x, y;
    vector<pair<int, int> > mers; //(weight, benefit)

    Town() {}
    Town(int x, int y) : x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(0);
    int N, M, W, T;
    cin >> N >> M >> W >> T;

    map<string, Merchandice> ms;
    for(int i = 0; i < M; ++i) {
        string name;
        int w, p;
        cin >> name >> w >> p;
        ms[name] = Merchandice(name, w, p);
    }

    vector<Town> towns;
    for(int i = 0; i < N; ++i) {
        Town t;
        int l;
        cin >> l >> t.x >> t.y;
        for(int j = 0; j < l; ++j) {
            string name;
            int q;
            cin >> name >> q;
            const Merchandice &m = ms[name];
            t.mers.push_back(make_pair(m.weight, m.price - q));
        }
        towns.push_back(t);
    }

    vector<int> dists(1<<N);
    vector<int> cost(1<<N);
    for(int pat = 0; pat < (1<<N); ++pat) {
        //cout << pat << endl;

        vector<int> order;
        vector<pair<int, int> > mers;
        for(int i = 0; i < N; ++i) {
            if(pat & (1<<i)) {
                order.push_back(i);
                const Town &t = towns[i];
                for(int j = 0; j < t.mers.size(); ++j) {
                    mers.push_back(t.mers[j]);
                }
            }
        }

        int mindist = 10000000;
        do {
            int d = 0;
            int prevx = 0, prevy = 0;
            for(int i = 0; i < order.size(); ++i) {
                d += abs(prevx - towns[order[i]].x) + abs(prevy - towns[order[i]].y);
                prevx = towns[order[i]].x;
                prevy = towns[order[i]].y;
            }
            d += abs(prevx) + abs(prevy);
            mindist = min(mindist, d);
        } while(next_permutation(order.begin(), order.end()));
        dists[pat] = mindist;

        sort(mers.begin(), mers.end());
        vector<int> dp(W+1, 0);
        int maxval = 0;
        for(int w = 1; w <= W; ++w) {
            for(int i = 0; i < mers.size(); ++i) {
                if(w - mers[i].first >= 0) {
                    dp[w] = max(dp[w], dp[w-mers[i].first] + mers[i].second);
                    maxval = max(maxval, dp[w]);
                }
            }
        }
        cost[pat] = maxval;
    }

    {
        vector<long long> dp(T+1, 0);
        long long maxval = 0;
        for(int t = 1; t <= T; ++t) {
            for(int i = 0; i < (1<<N); ++i) {
                if(t - dists[i] >= 0) {
                    dp[t] = max(dp[t], dp[t-dists[i]] + cost[i]);
                    maxval = max(maxval, dp[t]);
                }
            }
        }
        cout << maxval << endl;
    }
    
    return 0;
}