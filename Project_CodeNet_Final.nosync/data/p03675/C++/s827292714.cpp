#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

void solve(){
    int n;
    cin >> n;
    vector<int> even,odd;
    rep(i,0,n){
        int a;
        cin >> a;
        if(i%2==0) even.push_back(a);
        else odd.push_back(a);
    }

    if(n%2==0){
        reverse(odd.begin(),odd.end());
        vector<int> ans=odd;
        ans.insert(ans.end(),even.begin(),even.end());
        rep(i,0,n){
            cout << ans[i];
            if(i==n-1) cout << endl;
            else cout << " ";
        }
    }else{
        reverse(even.begin(),even.end());
        vector<int> ans=even;
        ans.insert(ans.end(),odd.begin(),odd.end());
        rep(i,0,n){
            cout << ans[i];
            if(i==n-1) cout << endl;
            else cout << " ";
        }
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
