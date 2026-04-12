#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    while(1){
        int n,l,r;
        cin >> n >> l >> r;
        if(n==0 && l==0 && r==0) break;
        vector<int> v(n);
        rep(i,n) cin >> v[i];
        int cnt = 0;
        for(int i=l; i<=r; i++){
            bool ok = 0;
            for(int j=0;j < n;j++){
                if(i%v[j] == 0){
                    ok = 1;
                    if((j+1) % 2 != 0){
                        cnt++;
                    } 
                    break;
                }
            }
            if(ok == 0 && n%2 == 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
