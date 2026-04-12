#include <bits/stdc++.h>
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rrepi(i,a,b) for(int i=((int)(b)-1);i>=(a);--i)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) rrepi(i,0,n)
#define debug(var)  do{std::cout << #var << " : "; view(var);}while(0)
using namespace std;
typedef long long ll;
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){for(const auto& v : vv){ view(v); } }
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void viewarr(T arr[], int n) { for(int i = 0; i < n; ++i) std::cout << arr[i] << " "; std::cout << std::endl; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;

int main() {
    int N,M;
    cin >> N >> M;
    if(N==M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
