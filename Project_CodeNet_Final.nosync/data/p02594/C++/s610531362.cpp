// 最適化
#pragma GCC target("avx")
#pragma GCC optimize("O3")

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>

#define endl "\n"
#define ll long long
#define REP(i,a,b) for (int i = (a); i < (int)(b); ++i)
#define IN_NUMS_V(vec, N) REP(i, 0, N) cin >> vec.at(i); // 入力される複数の数値を vector に代入する
#define OUT_V(vec) REP(i, 0, vec.size()) cout << vec.at(i) << endl;
#define V_SORT(vec) sort(vec.begin(), vec.end())
#define V_REVERSE(vec) sort(vec.rbegin(), vec.rend())

using namespace std;

///////////// BEGIN_LIB //////////////////
void sayYes(bool f){ if (f) cout << "Yes" << endl; else cout << "No" << endl; } // print 'Yes' or 'No'
void sayYES(bool f){ if (f) cout << "YES" << endl; else cout << "NO" << endl; } // print 'YES' or 'NO'
int gcd(int a, int b){ if (a%b==0) return(b); else return(gcd(b,a%b)); }        // 最大公約数
int lcm(int a, int b){ return a*b/gcd(a,b); }                                   // 最小公倍数
int digitSum(int n) { return (n < 10) ? n : digitSum(n / 10) + n % 10; }        // 各桁の和
bool isprime(ll n){                                                             // 素数判定
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    for (ll i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
///////////// END_LIB //////////////////

//////////// BEGIN_SOLVE ///////////////

void solve() {
    int X;
    cin >> X;
    sayYes(X >= 30);
}

//////////// END_SOLVE ///////////////
int main() { ios::sync_with_stdio(false); std::cin.tie(nullptr); solve(); return 0;}