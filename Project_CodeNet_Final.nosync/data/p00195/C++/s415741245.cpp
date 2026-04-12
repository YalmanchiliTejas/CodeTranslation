#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; };
    int s1, s2;
    pair<int, int> ds[5];
    string str = "ABCDE";

    for (;;) {
        scanf("%d %d", &s1, &s2);
        if (s1 == 0 && s2 == 0) break;
        for (int i = 0; i < 5; i++) ds[i] = {i, 0};
        ds[0].second = s1+s2;
        for (int i = 1; i < 5; i++) { scanf("%d %d", &s1, &s2); ds[i].second = s1+s2; }
        sort(ds, ds+5, cmp);
        printf("%c %d\n", str[ds[0].first], ds[0].second);
    }

    return 0;
}

