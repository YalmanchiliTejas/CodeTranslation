#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <utility>
#include <valarray>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);
    vector<unordered_set<int>> edges(N);
    for (int i = 0; i < M; ++i){
        int ai, bi;
        scanf("%d %d\n", &ai, &bi); --ai; --bi;
        edges[ai].emplace(bi);
        edges[bi].emplace(ai);
    }
    int result = 0;
    function<void(vector<int>)> countResult = [&](vector<int> v){
        if (v.size() == N){
            ++result;
        }
        int now = v.back();
        for (auto& next : edges[now]){
            bool flag = true;
            for (auto& vi : v){
                if (vi == next){
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            v.emplace_back(next);
            countResult(v);
            v.pop_back();
        }
    };
    countResult({0});
    printf("%d\n", result);
}
