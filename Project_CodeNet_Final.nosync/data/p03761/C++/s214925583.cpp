#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n;
    cin >> n;
    vector<int> a(26, 0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        a[s[i]-'a']++;
    }
    for(int i = 0; i < n-1; i++) {
        vector<int> b(26, 0);
        string t;
        cin >> t;
        for(int j = 0; j < t.size(); j++) {
            b[t[j]-'a']++;
        }
        for(int j = 0; j < 26; j++) {
            chmin(a[j], b[j]);
        }
    }
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < a[i]; j++) {
            cout << (char)('a'+i);
        }
    }
    cout << endl;
}