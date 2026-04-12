#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(26));
    rep(i, N){
        string a;
        cin >> a;
        rep(j, a.size()){
            S[i][a[j] - 'a']++;
        }
    }

    rep(i, 26){
        int num = INF;
        rep(j, N){
            num = min(num, S[j][i]);
        }
        rep(j, num) cout << char('a' + i);
    }
}