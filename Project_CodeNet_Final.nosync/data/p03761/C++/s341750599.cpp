#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;
        vector<string> S;
        vector<map<int, int>> m(n);
        for (int i = 0; i < n; ++i) {
                string str;
                cin >> str;
                S.push_back(str);
                for (int j = 0; j < str.length(); ++j) {
                        m[i][str[j]-'a']++;
                }
        }
        vector<int> cnt(26, 0);
        for (int k = 0; k < 26; ++k) {

                int minv = -1;
                for (int i = 0; i < n; ++i) {
                        int tmp = m[i][k];
                        if (minv == -1) minv = tmp;
                        else if (minv > tmp) minv = tmp;
                }
                cnt[k] = minv;

        }
        for (int k = 0; k < 26; ++k) {
                int tmp = cnt[k];
                if (tmp > 0) {
                        for (int i = 0; i < tmp; ++i) {
                                char cc = k + 'a';
                                cout << cc;
                        }
                }
        }

}
