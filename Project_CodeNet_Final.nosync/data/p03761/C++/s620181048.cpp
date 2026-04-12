#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
ll N, M;
string s;
int word[50][26];
int main(){
   cin >> N;
   REP(i,N){
       cin >> s;
       for(char c : s) ++word[i][c - 'a']; // 各文字の出現回数をカウント
   }

   string ans = "";
   REP(i,26){
       int cnt = 1e9;
       REP(j,N){
           cnt = min(word[j][i],cnt); // 出現数の最小値
       }
       char c = 'a' + i;
       REP(k,cnt) ans += c;
   }
   cout << ans << endl;
}