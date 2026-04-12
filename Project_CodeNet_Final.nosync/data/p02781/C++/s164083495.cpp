#include <bits/stdc++.h>

using namespace std;
#define N 100100
#define SIGMA 26

string s;
int t[128];
long long j, jj, i, n, ans, k;
int verif (){
    int it = 0;
    while (it< s.size() && s[it] - '0' == t[it])
        ++it;
    if (it == s.size())
        return 1;
    if (s[it] - '0' < t[it])
        return 0;
    return 1;
}
int main()
{
    cin >> s;
    cin >> k;
    if (k == 1){
        n = s.size();
        if (n > 1)
            ans = 9 * (n - 1);
        else
            ans = 0;
        ans += s[0] - '0';
    }
    if (k == 2){
        n = s.size();
        if (n > 2)
            ans = 81 * (n - 1) * (n - 2) / 2;
        else
            ans = 0;
        for (i = 1; i < s[0] - '0' + 1; ++i){
            t[0] = i;
            for (j = 1; j < s.size(); ++j){
                for (t[j] = 1; t[j] < 10; ++t[j])
                    ans += verif();
                t[j] = 0;
            }
        }
        if (n < 2)
            ans = 0;
    }
    if (k == 3){
        n = s.size();
        if (n > 3)
            ans = 729 * (n - 1) * (n - 2) * (n - 3) / 6;
        else
            ans = 0;
        for (i = 1; i < s[0] - '0' + 1; ++i){
            t[0] = i;
            for (j = 1; j < s.size(); ++j){
                for (t[j] = 1; t[j] < 10; ++t[j]){
                    for (jj = j + 1; jj < s.size(); ++jj){
                        for (t[jj] = 1; t[jj] < 10; ++t[jj])
                            ans += verif ();
                        t[jj] = 0;
                    }
                }
                t[j] = 0;
            }
        }
        if (n < 3)
            ans = 0;
    }
    cout << ans;
    return 0;
}
