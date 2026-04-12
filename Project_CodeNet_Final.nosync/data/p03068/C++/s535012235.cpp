#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF (ll)1e18
#define MOD (ll)1e9 + 7
#define pb push_back

typedef long long ll;
typedef long long int llt;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

char dif = 'A' - 'a';
int mod = 1e9 + 7;
ll inf = 1e18;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    char tmp = s[k - 1];
    for (int i = 0; i < n;i++){
        if(s[i]!=tmp)
            s[i] = '*';
    }
    cout << s << endl;
}