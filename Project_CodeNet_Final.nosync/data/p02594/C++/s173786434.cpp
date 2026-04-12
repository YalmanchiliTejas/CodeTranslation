#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define REP(i,a,b) for(int i=int(a);i<(int)b;++i)
#define Graph vector<vecctor<ll>>
#define pairs vector<pair<ll,ll>>
#define pb push_back



using namespace std;
using ll = long long;
const ll INF = 1e18;
const double PI = acos(-1);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}



int main(void)
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    int x;
    cin >> x;
    if(x >=30){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    return 0;
}
