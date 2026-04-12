#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    deque<int> d;

    for (int i = 0; i < n; i++) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (p == 0) d.push_front(a[i]);
        else d[p-1] = a[i];
    }

    cout << d.size() << endl;
    
    return 0;
}