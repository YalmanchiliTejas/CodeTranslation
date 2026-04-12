#include <bits/stdc++.h>


using namespace std;

#ifdef CLION
ifstream ifs("/home/kyuridenamida/CLionProjects/project/input.txt");
#define cin ifs
#define scanf DONT_USE_SCANF
#endif

typedef long long ll;

int main() {
    string s;
    int k;
    cin >> s >> k;

    long long ans = 0;
    set<string> cands;
    if (k == 1) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j < 10; j++) {
                string w = string(s.size(), '0');
                w[i] = '0' + j;

                cands.insert(w);
            }
        }
    } else if (k == 2) {
        for (int i = 0; i < s.size(); i++) {
            for (int i2 = i + 1; i2 < s.size(); i2++) {
                for (int j = 1; j < 10; j++) {
                    for (int j2 = 1; j2 < 10; j2++) {
                        string w = string(s.size(), '0');
                        w[i] = '0' + j;
                        w[i2] = '0' + j2;
                        cands.insert(w);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                // special
                for (int i2 = i + 1; i2 < s.size(); i2++) {
                    for (int i3 = i2 + 1; i3 < s.size(); i3++) {
                        for (int j = 1; j < 10; j++) {
                            for (int j2 = 1; j2 < 10; j2++) {
                                for (int j3 = 1; j3 < 10; j3++) {
                                    string w = string(s.size(), '0');
                                    w[i] = '0' + j;
                                    w[i2] = '0' + j2;
                                    w[i3] = '0' + j3;
                                    if (w <= s) {
                                        ans++;
                                    }
                                }
                            }
                        }

                    }
                }
            } else {
                ans += 9ll * 9ll * 9 * (s.size() - i - 1) * (s.size() - i - 2) / 2;
            }
        }
    }

    for (auto c : cands) {
        if (s >= c) {
            ans++;
        }
    }
    cout << ans << endl;

}
