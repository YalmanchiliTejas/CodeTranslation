#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int ans[26], cnt[26], n, a = 0;
    string buf;
    char w[26];

    for (char x = 'a'; x <= 'z'; x++, a++)
    {
        w[a] = x;
    }

    cin >> n;
    for (int i = 0; i < 26; i++)
    {
        ans[i] = 0;
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        for (int j = 0; j < buf.size(); j++)
        {
            for (int k = 0; k < 26; k++)
            {
                if (w[k] == buf[j]) {
                    cnt[k]++;
                    break;
                }
            }
        }
        for (int j = 0; j < 26; j++)
        {
            if (i != 0) {
                ans[j] = min(ans[j], cnt[j]);
            } else {
                ans[j] = cnt[j];
            }
            cnt[j] = 0;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (ans[i] != 0) {
            for (int j = ans[i]; j > 0; j--)
                cout << w[i];
        }
    }
    cout << endl;

    return 0;
}
