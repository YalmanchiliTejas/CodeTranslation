#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1001001001001001;


ll dp[200001];
ll a[200001];
ll dpall[200001];
int n;


ll init(){
    rep(i,200001) dp[i]=-INF;
    rep(i,200001) dpall[i]=-INF;
    return 0;
}

ll rec(int x, int k){
    //cout << "x:" << x << "k:" << k << endl;
    if(k*2>x) return dpall[x];
    if(k==0) return ll(0);
    if(dp[x]>-INF) return dp[x];

    ll res = -INF;

    ll temp = 0;
    temp += a[x-1];
    temp += rec(x-2,k-1);
    //cout << "x-2:k-1 " << x-2 << " : "  << k-1 << "  " << temp << endl;
    res = max(res,temp);


    temp = 0;
    temp += a[x-2];
    temp += rec(x-3,k-1);
    /*
    cout << "x-3:k-1 " << x-3 << " : "  << k-1 << "  " << temp << endl;
    cout << a[x-2] << " " << rec(x-3,k-1) << endl;
    */
    res = max(res,temp);

    if(x%2==0) return dp[x]=res;

    temp = 0;
    temp = dpall[x-2];
    //cout << "x-2:k " << x-2 << " : "  << k << "  " << temp << endl;
    res = max(res,temp);

    return dp[x]=res;
}

int main(){
    cin >> n;
    rep(i,n) cin >> a[i];
    
    init();
    for(int i=1; i<=n/2; ++i){
        if(i==1){
            dpall[1]=a[0];
            continue;
        }
        dpall[2*i-1] = dpall[2*i-3]+a[2*i-2];
    }

    /*
    cout << "dpall" << endl;
    for(int i=1; i<=n; i+=2){
        cout <<"i" << i <<" : "<<dpall[i] << endl;
    }*/

    cout << rec(n,n/2) << endl;

}
