#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

bool f(string s,string t){
    for (int i = 0; i < min(s.length(), t.length()); i++) {
        if(s[i] < t[i]) return true;
        else if(s[i] > t[i]) return false;
    }
    return true;
}

int main(){
    int n;cin >> n;
    string ss,tt;cin >> ss >> tt;
    if(tt.length() < ss.length()) swap(ss, tt);
    string s = ss,t = tt;
    while(s.length() < n) s += ss;
    while(t.length() < n) t += tt;
    if(!f(s, t)){
        swap(ss,tt);
    }
    for (int i = 0; tt.length() * i <= n; i++) {
        int k = tt.length() * i;
        if((n - k) % ss.length() == 0){
            string ans = "";
            for (int j = 0; j < (n - k) / ss.length(); j++) {
                ans += ss;
            }
            for (int j = 0; j < i; j++) {
                ans += tt;
            }
            cout << ans << endl;
            return 0;
        }

    }
    return 0;
}
