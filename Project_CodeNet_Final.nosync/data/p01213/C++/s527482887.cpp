#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[301][301];
int maxn, maxm, maxlen;
string str;

void lcs(int n, int m, bool rest = true) {
    for (int i = 0; i < n; i++) fill(dp[i], dp[i]+m+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i] == str[n+j]) {
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    if (rest && dp[n][m] > maxlen) {
        maxlen = dp[n][m];
        maxn = n, maxm = m;
    }
}

void getSubseq() {
    char seq[maxlen+1];
    seq[maxlen] = '\0';
    string x = str.substr(0, maxn);
    string y = str.substr(maxn);
    lcs(maxn, maxm, false);
    int i = maxn, j = maxm;
    int index = maxlen;

    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            seq[index-1] = x[i-1];
            i--; j--; index--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    cout << seq << endl;
}



int main()
{
    for (; ;) {
        cin >> str;
        if (str == "#END") break;
        maxlen = 0;
        int size = str.size();
        for (int i = 1; i < str.size(); i++) {
            lcs(i, size-i);
        }
        getSubseq();
    }
    return 0;
}

