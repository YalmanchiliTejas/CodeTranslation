#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    vector<vector<int> > num(26, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            num[str[j]-97][i]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        int mini = 50;
        for (int j = 0; j < n; j++) {
            mini = min(mini, num[i][j]);
        }
        for (int j = 0; j < mini; j++) {
            cout << char('a'+ i);
        }
    }

	return 0;
}
