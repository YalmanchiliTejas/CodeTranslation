#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define FOR(i,s,e) for(int i=(s);i<(e);i++)
#define REP(i,n) FOR(i,0,n)

int main(){
    int n, q;
    cin >> n >> q;
    LL st = 0;
    REP(i, q){
        int a, k;
        cin >> a >> k;
        if(a==0){
            LL ans = (k+st)%n;
            if(ans == 0) ans = n;
            cout << ans << endl;
        }else{
            st = (st+k)%n;
        }
    }

        return 0;
}

