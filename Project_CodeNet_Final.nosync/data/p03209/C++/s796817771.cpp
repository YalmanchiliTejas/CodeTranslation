#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; (i) < (n); ++ (i))
#define loop(i,a,n) for (int i = (a); (i) < (n); ++ (i))
#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 0
#define int long long
//#define int ll
using namespace std;
typedef vector<int> vi;
 
signed main(){
    int N,X;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    vector<int> niku(N+1),dpketa(N+1);
    rep(i,N+1) {
        if(i==0) dpketa[i] = 1;
        else {
            dpketa[i] = 3 + 2*dpketa[i-1];
        }
    }
    rep(i,N+1)
    {
        if(i==0) {
            niku[i] = 1;
        } else {
            niku[i] = 1 + 2*niku[i-1];
        }
    }
    int count = 0;
    int pp,sa = X;
    for(pp=N;pp>=0;pp--) {
    if(pp > 1) {
        if(sa == dpketa[pp]) {
            count += niku[pp];
            break;
        } else if(sa > (dpketa[pp-1]+2)) {
            count += niku[pp-1] + 1;
            sa -= dpketa[pp-1] + 2;
        } else if(sa ==(dpketa[pp-1]+2)) {
            count += niku[pp-1] + 1;
            break;
        } else if(sa > 1) {
            sa -= 1;
        } else if(sa == 1) {
            break;
        }
    } else if(pp == 1){
        switch(sa) {
            case 1: break;
            case 5:
            case 4: count++;
            case 3: count++;
            case 2: count++;
        }
        break;
    } else if(pp == 0 && sa == 1) {
        count++;
        break;
    } else break;
    }
    cout << count << endl;
    return 0; 
}
