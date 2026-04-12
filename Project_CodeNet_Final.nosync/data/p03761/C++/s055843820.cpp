#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    const int p = 26;
    vector<int> alphabetNum(p, 0);

    for (char k = 'a'; k <= 'z'; k++) {
        int commonNum = 100;
        for (int i = 0; i < n; i++) {            
            int tmp = 0;
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == k) tmp++;         
            }
            commonNum = min(commonNum, tmp);
        }
        alphabetNum[k - 'a'] += commonNum;
    }

    for (char i = 'a'; i <= 'z'; i++) {        
        for (int j = 0; j < alphabetNum[ i- 'a']; j++) {
            cout << i;
        }
    }
    return 0;
}