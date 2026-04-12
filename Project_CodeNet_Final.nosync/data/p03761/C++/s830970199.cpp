#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1010101010
#define MOD 1000000007
#define LL long long
using Coord = pair<int, int>;

int cnt[30][51];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (const char &c: tmp) cnt[c - 'a'][i]++;
    }
 
    for (int i = 0; i <= 'z' - 'a'; i++) {
        int c = *min_element(cnt[i], cnt[i]+n);
        rep(j, c)
            cout << (char)('a' + i);
    }
    cout << endl;
}