#include <bits/stdc++.h>
using namespace std;

size_t combination(size_t n, size_t k) {
    if (n < k) {
        return 0;
    }
    size_t ns = 1, ks = 1;
    for (; k > 0; k--, n--) {
        ns *= n;
        ks *= k;
    }
    return ns / ks;
}

size_t count(const string& s, size_t i, int k) {
    if (i == s.size() && k != 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    int topNum = s[i] - '0';
    assert(topNum != 0);
    size_t next = i + 1;
    while (next < s.size() && s[next] == '0') {
        next++;
    }
    size_t restSize = s.size() - i - 1;
    return pow(9, k) * combination(restSize, k)
        + (topNum - 1) * pow(9, k - 1) * combination(restSize, k - 1)
        + count(s, next, k - 1);
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << count(s, 0, k) << endl;
    return 0;
}
