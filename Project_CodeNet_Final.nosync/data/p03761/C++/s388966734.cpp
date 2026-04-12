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
    int cnt[51][30];
 
    for (int i = 0; i < 51; i++)
        for (int j = 0; j < 30; j++)
            cnt[i][j] = 0;
    
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (char &c: tmp) cnt[i][c - 'a']++; 
    }
 
    for (int i = 0; i <= 'z' - 'a'; i++) {
        int c = INF;
        for (int j = 0; j < n; j++) {
            c = min(c, cnt[j][i]);
        }
        for (int j = 0; j < c; j++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}