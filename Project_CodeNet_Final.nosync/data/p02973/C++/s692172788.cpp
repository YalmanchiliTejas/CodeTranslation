#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;

int main()
{
    int n;
    cin >> n;
    deque<int> a;
    int x;
    cin >> x;
    a.push_back(x);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= a[0])
        {
            a.push_front(x);
        }
        else
        {
            int p = lower_bound(a.begin(), a.end(), x) - a.begin();
            a[p - 1] = x;
        }
    }
    cout << a.size() << endl;

    return 0;
}