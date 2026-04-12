#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<int> vint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;

lint powint(lint x, lint y){
    int ret = 1;
    for (int i=0; i < y; i++) ret *= x;
    return ret;
};

lint mod = 1000000007;
vector<int> dx = {1, 0, 0, -1, 1, 1, -1, -1};
vector<int> dy = {0, -1, 1, 0, 1, -1, 1, -1};

map<char, long long> counter(string s){
    map<char, long long> count;
    rep(i, s.size()){
        count[s[i]] ++;
    }
    return count;
};

int powmod(int x, int y, int m){
    if (y == 0) return 1;
    return ((powint(powmod(x, y>>1, m), 2) % m) * powint(x, (y & 1))) % m;
};

int main() {
    lint n; cin >> n;
    vlint a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    lint cnt = 0;
    vlint ans1;
    vlint ans2;
    lint left = 0;
    lint right = n-1;
    while (true){
        if (cnt % 2 == 0){
            ans1.push_back(abs(a[left]));
            cnt ++; left ++;
        }
        else{
            ans1.push_back(abs(a[right]));
            cnt ++; right --;
        }
        if (ans1.size() == n) break;
    }
    ans1.push_back(ans1[0]);

    left = 0; right = n-1; cnt = 0;
    while (true){
        if (cnt % 2 == 1){
            ans2.push_back(abs(a[left]));
            cnt ++; left ++;
        }
        else{
            ans2.push_back(abs(a[right]));
            cnt ++; right --;
        }
        if (ans2.size() == n) break;
    }
    ans2.push_back(ans2[0]);

    lint a1 = 0;
    lint a1_min = abs(ans1[0] - ans1[1]);
    lint a2 = 0;
    lint a2_min = abs(ans2[0] - ans2[1]);

    rep(i, n){
        lint r1 = abs(ans1[i] - ans1[i+1]);
        a1 += r1;
        a1_min = min(a1_min, r1);

        lint r2 = abs(ans2[i] - ans2[i+1]);
        a2 += r2;
        a2_min = min(a2_min, r2);
    }

    cout << max(a1 - a1_min, a2 - a2_min) << endl;
    



}

