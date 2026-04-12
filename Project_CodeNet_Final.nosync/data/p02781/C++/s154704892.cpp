#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string n;int k;cin>>n>>k;
    if (n.size()<k) {
        cout << 0 << endl;
        return 0;
    }
    if (n=="10"&&k==2 || n.size()==3&&stoi(n)<=110&&k==3) {
        cout << 0 << endl;
        return 0;
    }
    ll ns = n.size();
    ll cur = 0;
    ll res = 0;
    while(k>0&&cur<ns) {
        if (n[cur]=='0') {
            cur++;
            continue;
        }
        ll digit = n[cur]-'0', rem=ns-1-cur;
        if (k==3) {
            res += (digit-1) * 9*9*rem*(rem-1)/2;
            res += 9*9*9*rem*(rem-1)*(rem-2)/6;
        }
        else if(k==2) {
            res += (digit-1) * rem * 9;
            res += 9*9*rem*(rem-1)/2;
        }
        else {
            res += digit;
            res += 9*rem;
        }
        k--;
        cur++;
    }
    cout << res << endl;
    return 0;
}
