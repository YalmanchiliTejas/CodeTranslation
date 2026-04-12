#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /*string S; long long K;
    cin >> S >> K;
    int N = S.size();
    vector<int> perm(N);
    for(int i = 0; i < N; ++i) {
        perm[i] = i;
    }
    sort(perm.begin(), perm.end(), [&](int i, int j) {
        if(S[i] != S[j]) return S[i] < S[j];
        return i < j;
    });
    vector<int> bit(N + 1);
    function<void(int, int)> add = [&](int pos, int x) {
        for(int i = pos + 1; i <= N; i += i & (-i)) {
            bit[i] += x;
        }
    };
    function<int(int)> sum = [&](int r) {
        int ans = 0;
        for(int i = r; i >= 1; i -= i & (-i)) {
            ans += bit[i];
        }
        return ans;
    };
    for(int i = 0; i < N; ++i) {
        add(i, 1);
    }
    string str;
    for(int i : perm) {
        int u = sum(i);
        if(K >= u) {
            K -= u;
            add(i, -1);
            str += S[i];
        }
    }
    for(int i = 0; i < N; ++i) {
        if(sum(i) != sum(i + 1)) {
            str += S[i];
        }
    }
    for(int i = 1; i < N; ++i) {
        int ptr = i;
        while(ptr != 0 && K > 0 && str[ptr - 1] > str[ptr]) {
            swap(str[ptr - 1], str[ptr]);
            --ptr;
            --K;
        }
    }
    cout << str << endl;*/

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)cin >> d[i];

    int nowmax = 0;
    bool ret = true;
    for (int i = 0; i < n; i++) {
        if (nowmax < i) {
            ret = false;
            break;
        }
        nowmax = max(nowmax, i + d[i] / 10);
    }
    int nowmin = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (nowmin > i) {
            ret = false;
            break;
        }
        nowmin = min(nowmin, i - d[i] / 10);
    }

    cout << (ret ? "yes" : "no") << endl;
    return 0;
}
