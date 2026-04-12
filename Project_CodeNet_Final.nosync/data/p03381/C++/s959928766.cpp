#define errOut(s) { std::cerr << "LINE:" << __LINE__ << " " << #s << " = " << s << std::endl; }

#include <bits/stdc++.h>

using namespace std;

#ifndef errOut
#define errOut(s)
#endif

using Value = int64_t;

struct ValueInfo {
    Value value;
    int idx;
};

std::vector<Value> calc(const std::vector<Value> &as) {
    auto n = static_cast<const int>(as.size());
    auto m = n  / 2;
    std::vector<Value> ret(n, 0);
    std::vector<ValueInfo> valueInfos(n, ValueInfo());

    for (int i = 0; i < n; ++i) {
        valueInfos[i].value = as[i];
        valueInfos[i].idx = i;
    }
    std::sort(valueInfos.begin(), valueInfos.end(), [](const ValueInfo& x, const ValueInfo& y) {
       return x.value < y.value;
    });
    std::vector<int> infoIdxes(n, 0);
    for (int i = 0; i < n; ++i) {
        infoIdxes[valueInfos[i].idx] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (infoIdxes[i] >= m) {
            ret[i] = valueInfos[m - 1].value;
        } else {
            ret[i] = valueInfos[m].value;
        }
    }
    return ret;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Value> as(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> as[i];
    }
    auto ret = calc(as);
    for (int i = 0; i < n; ++i) {
        std::cout << ret[i] << std::endl;
    }
    return 0;
}
