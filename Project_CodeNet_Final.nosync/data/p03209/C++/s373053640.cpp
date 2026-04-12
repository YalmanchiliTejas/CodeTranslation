#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define int long long
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;

int hb[51];
int pn[51];


int sol(int l,int v){
    if(v==0) return 0;
    if(l==0) return 1;
    if(v==1) return 0;
    if(v<=1+hb[l-1]){
        return sol(l-1,v-1);
    }else{
        return pn[l-1]+1+sol(l-1,v-2-hb[l-1]);
    }


}



signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N,X;
    cin>>N>>X;
    hb[0]=1;
    pn[0]=1;
    for(int i=1;i<=50;i++){
        hb[i]=2*hb[i-1]+3;
        pn[i]=2*pn[i-1]+1;
    }
    int ans=sol(N,X);
    cout << ans << endl;





}
