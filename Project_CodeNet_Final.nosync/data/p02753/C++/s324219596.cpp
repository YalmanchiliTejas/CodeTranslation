#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cctype>
#define len length()
#define sz size()
#define rng(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) rng(i, 0, n)
#define srt(v) sort(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define vi(a, n) vector<int> a(n)
#define vs(a, n) vector<string> a(n)
#define vc(a, n) vector<char> a(n)
#define psb(a) push_back(a)
#define ppb pop_back()
#define erc(S, i) S.erase(S.begin() + i)
#define ers(S, i, j) S.erase(S.begin() + i, S.begin() + j)
#define sp(n) cout << setprecision(n) << fixed
#define fst(s) s.at(0)
#define lst(s) s.at(s.len - 1)
typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(){
    string S;
    cin >> S;
    if(S.at(0) == S.at(1) && S.at(1) == S.at(2)) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}