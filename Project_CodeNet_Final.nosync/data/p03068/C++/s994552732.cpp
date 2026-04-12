#include <bits/stdc++.h>
using namespace std;

#define cc(x) cout << (x) << endl
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define repi(i,a,b) for(int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<long long> vll;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const ll inf = 1LL<<58;
const int iinf = 1<<30;

int main(){
    ll n, k;
    string s;
    cin >> n >> s >> k;
    char a;
    a = s[k-1];
    rep(i,n){
        if(s[i]!=a){
            s[i]='*';
        }
    }
    cc(s);
}