#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
#define int long long
#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#ifdef DEBUG
std::ostream& dout = cout;
#else
stringstream dout;
#endif
template<typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) {
    in >> p.first >> p.second;
    return in;
}

signed main(signed argc, char* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int MOD = 1000000007;
    set<char> st;
    rep(i,3){
        char c;
        cin>>c;
        st.insert(c);
    }
    if(st.size()==1){
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}
