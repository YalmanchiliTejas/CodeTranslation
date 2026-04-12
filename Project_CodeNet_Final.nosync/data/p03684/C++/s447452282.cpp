#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <memory>
#include <valarray>
#include <climits>

using namespace std;

using ll = long long int;

#define loop(i, N) for (int i = 0; i < N; ++i)
#define scanInt(x) int x; scanf("%d", &x); getchar();
#define scanLLInt(x) ll x; scanf("%lld", &x); getchar();
#define scanVecInt(A, N) vector<int> A(N); loop(i, N){scanf("%d", &(A[i])); getchar();}
#define scanVecLLInt(A, N) vector<ll> A(N); loop(i, N){scanf("%lld", &(A[i])); getchar();}

int main()
{
    scanInt(N);
    vector<pair<int, int>> V; V.reserve(N);
    loop(i, N){
        scanInt(xi);
        scanInt(yi);
        V.emplace_back(xi, yi);
    }
    auto dist = [&](int xn, int yn){
        return min(abs(V[xn].first - V[yn].first), abs(V[xn].second - V[yn].second));
    };
    ll result = 0;
    multimap<int, int> xs;
    multimap<int, int> ys;
    loop(i, N){
        xs.emplace(V[i].first, i);
        ys.emplace(V[i].second, i);
    }
    auto remove_i = [&](int c){
        auto xit = xs.equal_range(V[c].first).first;
        while (xit->second != c) ++xit;
        xs.erase(xit);
        auto yit = ys.equal_range(V[c].second).first;
        while (yit->second != c) ++yit;
        ys.erase(yit);
    };
    unordered_set<int> used;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> passes;
    // multimap<int, int> passes;
    passes.emplace(0, 0);
    while (used.size() < N){
        // int len = passes.begin()->first;
        // int c = passes.begin()->second;
        // passes.erase(passes.begin());
        int len = passes.top().first;
        int c = passes.top().second;
        passes.pop();

        if (!used.insert(c).second) continue;
        result += len;
        remove_i(c);

        {
            auto xu = xs.lower_bound(V[c].first);
            if (xu != xs.end()) passes.emplace(dist(xu->second, c), xu->second);
            auto xl = xs.upper_bound(V[c].first);
            if (xl != xs.begin()) --xl;
            if (xl != xs.end()) passes.emplace(dist(xl->second, c), xl->second);
            auto yu = ys.lower_bound(V[c].second);
            if (yu != ys.end()) passes.emplace(dist(yu->second, c), yu->second);
            auto yl = ys.upper_bound(V[c].second);
            if (yl != ys.begin())--yl;
            if (yl != ys.end()) passes.emplace(dist(yl->second, c), yl->second);
        }

        // loop(i, N){
        //     if (used.find(i) == used.end()) {
        //         passes.emplace(dist(i, c), i);
        //     }
        // }
    }
    printf("%lld\n", result);
}
