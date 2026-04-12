#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define rrep(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////



int main() {
    int n; cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    deque<ll> d;
    d.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        int b = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (b == 0) d.push_front(a[i]);
        else d[b-1] = a[i];
    }
    
    cout << d.size() << endl;
    
    return 0;
}
