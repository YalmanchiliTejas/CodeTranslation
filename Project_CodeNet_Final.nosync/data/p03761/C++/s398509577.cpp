#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
        const int alpha_num = 'z' - 'a' + 1;
        int alpha[alpha_num] = {};
        int n;
        cin >> n;
        vector<string> S(n);
        for (int i = 0; i < n; i++) {
                cin >> S[i];
        }

        for (char& c : S[0]) {
                alpha[c - 'a']++;
        }
        for (int i = 1; i < S.size(); i++) {
                int tmp[alpha_num] = {};
                for (char& c : S[i]) {
                        tmp[c - 'a']++;
                }
                for (int j = 0; j < alpha_num; j++) {
                        alpha[j] = min(tmp[j], alpha[j]);
                }
        }

        for (int i = 0; i < alpha_num; i++) {
                for (int j = 0; j < alpha[i]; j++) {
                        cout << (char)('a' + i);
                }
        }
        cout << endl;
        return 0;
}