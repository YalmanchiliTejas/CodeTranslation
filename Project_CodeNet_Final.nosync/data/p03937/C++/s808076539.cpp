#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i,H) cin >> A[i];
    int cnt = 0;
    rep(i,H)rep(j,W){
        if(A[i][j]=='#')cnt++;
    }
    if(cnt==(H+W-1)){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}