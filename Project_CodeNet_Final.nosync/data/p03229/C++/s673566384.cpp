#include <bits/stdc++.h>
using namespace std;

long answer(list<int> l) {
    long ans = 0;

    int before = -1;
    for(auto itr = l.begin(); itr != l.end(); ++itr) {
        if (before == -1) {
            before = *itr;
            continue;
        }

        ans += abs(*itr - before);
        before = *itr;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    list<int> la;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int idx_min, idx_max;
    int dfront, dback;

    // 最大値を中央に置き、最小値を最大値の左右に置いてから、並べ替えを行うパターン
    la.push_back(a[n - 1]);

    idx_min = 0;
    idx_max = n - 2;

    bool place_min_num = true;
    while (idx_min <= idx_max) {
        if (place_min_num) {
            la.push_front(a[idx_min++]);

            if (idx_min > idx_max) {
                break;
            }

            la.push_back(a[idx_min++]);
        } else {
            la.push_front(a[idx_max--]);

            if (idx_min > idx_max) {
                break;
            }

            la.push_back(a[idx_max--]);
        }

        place_min_num = !place_min_num;
    }

    long ansA = answer(la);

    // 最小値を中央に置き、最大値を最小値の左右に置いてから、並べ替えを行うパターン
    la.clear();
    la.push_back(a[0]);

    idx_min = 1;
    idx_max = n - 1;

    place_min_num = false;
    while (idx_min <= idx_max) {
        if (place_min_num) {
            la.push_front(a[idx_min++]);

            if (idx_min > idx_max) {
                break;
            }

            la.push_back(a[idx_min++]);
        } else {
            la.push_front(a[idx_max--]);

            if (idx_min > idx_max) {
                break;
            }

            la.push_back(a[idx_max--]);
        }

        place_min_num = !place_min_num;
    }

    long ansB = answer(la);

    std::cout << std::max(ansA, ansB) << endl;

    return 0;
}
