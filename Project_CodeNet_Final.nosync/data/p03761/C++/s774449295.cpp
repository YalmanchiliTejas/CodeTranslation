#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 51
#define INF 10000
typedef long long int ll;
using namespace std;

int n;
int cnt[MAX_SIZE + 1][26];

int main()
{
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < s.size(); j++){
            cnt[i][s[j] - 'a']++; //文字列当たりに何個あるか調べる
        }
    }

    for (int i = 0; i < 26; i++){
        cnt[MAX_SIZE][i] = INF; //最終的にアルファベットの使える個数を格納
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 26; j++){
            cnt[MAX_SIZE][j] = min(cnt[MAX_SIZE][j], cnt[i][j]);
        }
    }

    for (int i = 0; i < 26; i++){
        char alpha = 'a' + i;
        for (int j = 0; j < cnt[MAX_SIZE][i]; j++){
            cout << alpha;
        }
    }
    cout << "\n";
    return 0;
}