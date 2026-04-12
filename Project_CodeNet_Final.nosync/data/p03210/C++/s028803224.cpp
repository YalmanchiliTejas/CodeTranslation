#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cmath>
#define INF 2000000000
#define REP(i,b,n) for(int i = (b); i < n; i++)
#define rREP(i,b,n) for(int i = n; i >= b; i--)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const string lowercase = "abcdefghijklmnopqrstuvwxyz";
const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int gcd(int a, int b){return b ? gcd(b, a % b): a;}

int main()
{
    int x;
    cin >> x;
    if (x == 3 || x == 5 || x == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
