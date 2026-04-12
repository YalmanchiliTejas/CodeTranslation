#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int n;
    cin >> n;

    map<char, int> mp;
    for (char i='a'; i<='z'; i++) mp[i] = INT_MAX;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        map<char, int> tmp;
        for (const auto& c : s) tmp[c]++;

        for (char j='a'; j<='z'; j++) mp[j] = min(mp[j], tmp[j]);
    }

    for (char i='a'; i<='z'; i++) {
        cout << string(mp[i], i);
    }
    cout << endl;
}