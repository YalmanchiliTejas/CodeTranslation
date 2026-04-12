//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int lb(vi &min, int &g, int a, int b) {
    if(b-a == 1) {
        return b;
    }
    int c = (a+b)/2;
    if(min[c] >= g) {
        a = c;
    } else {
        b = c;
    }
    return lb(min, g, a, b);
}

 
int main() {
    int n;
    cin >> n;
    vector<int> min(1);
    min[0] = 1000000001;
    int ans = 0;
    rep(i, n) {
        int g;
        cin >> g;
        if(min[min.size()-1] >= g) {
            ++ans;
            min.push_back(g);

        } else {
            int num = lb(min, g, 0, min.size());
            min[num] = g;
        }
        
    }

    cout << ans << endl;
}
