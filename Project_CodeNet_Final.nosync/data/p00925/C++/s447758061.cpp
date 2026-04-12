#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S; cin >> S;
    int M; cin >> M;

    int a = S[0] - '0';
    vector<int> bs = {S[0] - '0'};
    for(int i = 2; i < S.size(); i += 2) {
        int si = S[i] - '0';
        if(S[i - 1] == '+') {
            a = a + si;
            bs.push_back(si);
        } else if(S[i- 1] == '*') {
            a = a * si;
            bs.back() = bs.back() * si;
        } else assert(0);
    }
    int b = 0;
    for(int i : bs) b += i;
    if(a == M and b == M) cout << "U" << endl;
    else if(a == M) cout << "L" << endl;
    else if(b == M) cout << "M" << endl;
    else cout << "I" << endl;    
    
    return 0;
}