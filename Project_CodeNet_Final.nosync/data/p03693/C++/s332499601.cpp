#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

bool check(string tmp) {
    // cout << tmp << endl;
    if(tmp.length() % 2 == 1) {
        cout << "nope" << endl;
        return false;
    } else {
        int len = tmp.length();
        string before = tmp.substr(0, len / 2);
        string after = tmp.substr(len / 2);
        // cout << before << ":" << after << endl;
        return before == after;
    }
}
int main() {
   int r,g,b;
  cin>>r>>g>>b;
  if((100*r+10*g+b)%4==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
    return 0;
}