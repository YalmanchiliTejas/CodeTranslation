#include "bits/stdc++.h"
using namespace std;

#define all(x)  x.begin(), x.end()
#define mp      make_pair
#define pii     pair<int, int>
#define pll     pair<long long, long long>
#define ll      long long

int main() {
        string s;
        cin >> s;
        for (int i = 0; i < s.size() - 1; i ++) {
                if (s[i] == 'A' && s[i + 1] == 'C') {
                        cout << "Yes" << endl;
                        return 0;
                }
        }
        cout << "No" << endl;
        return 0;
        return 0;
}

