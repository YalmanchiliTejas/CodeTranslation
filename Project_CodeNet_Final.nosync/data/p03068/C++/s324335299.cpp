#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b){ a>b?:a=b; }
template<class T, class C> void chmin(T& a, C b){ a<b?:a=b; }
int main(int argc, char* argv[]) {
   int n, k;
   string s;
   cin >> n >> s >>k;
   rep(i, n){
       if(s[i]!=s[k-1]) s[i] = '*';
   }
   cout << s << endl;
    return 0;
}
