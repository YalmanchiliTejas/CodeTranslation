#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG
 
// 型名の省略
typedef unsigned int uint;
typedef long long lint;
typedef unsigned long long ulint;
 
const int MOD = 1000000007;
const double PI=acos(-1.0);
 
// cinとcoutの高速化
#define endl "\n"
struct cinacc{cinacc(){cin.tie(0);ios::sync_with_stdio(false);}}cinaccc;
struct coutacc{coutacc(){cout.setf(ios::fixed);cout.precision(12);}}coutaccc;
 
// 繰り返し
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep_(i,n) for(int i=0;i<(int)(n-1);i++)
#define rep__(i,n) for(int i=n-1;i>=0;i--)
 
int main(void) {
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) cout << "No";
    else cout << "Yes";
    return 0;
}
