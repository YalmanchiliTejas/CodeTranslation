#include <bits/stdc++.h>
using namespace std;

#define cc(x) cout << (x) << endl
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define repi(i,a,b) for(int i = int(a); i < int(b); ++i)
typedef long long ll;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const ll inf = 1LL<<58;
const int iinf = 1<<30;

int main(){
    int n;
    cin >> n;
    int h[n];
    rep(i,n){
        cin >> h[i];
    }
    int tmp=1;
    int ok=0;
    repi(i,1,n){
        repi(j,0,i){
            if(h[i]<h[j]){
                ok=1;
            }   
        }
        if(ok==0){
            tmp++;
        }
        ok=0;
    }   
    cc(tmp);
}