//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


 
int main() {
    int n;
    cin >> n;
    deque<int> d;
    int ans = 0;
    rep(i, n) {
        int g;
        scanf("%d", &g);
        auto itr = lower_bound(d.begin(), d.end(), g);
        if(d.begin() == itr) {
            d.push_front(g);
        } else {
            *(itr-1) = g;
        }
        
    }

    cout << d.size() << endl;
}