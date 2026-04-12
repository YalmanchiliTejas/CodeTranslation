#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

typedef pair<int, int> P;

int main() {

    int n,m;
    cin >> n >> m;
    vector<P> p(m);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        p[i] = P(a,b);
    }

    vector<int> v(n);
    rep(i,n){
        v[i] = i;
    }

    int ans = 0;
    do{
        bool ok = true;
        rep(i,n-1){
            P tmp1 = P(v[i],v[i+1]);
            P tmp2 = P(v[i+1],v[i]);
            if(find(p.begin(), p.end(), tmp1)==p.end() && find(p.begin(), p.end(), tmp2) ==p.end()){
                ok = false;
                break;
            }
        }
        if(ok){
            ans++;
        }
    }while(next_permutation(v.begin()+1,v.end()));

    cout << ans << endl;
    

    return 0;
}