#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIII pair< int, pair<int,int> >
const int MaxN = 3005;
ll dp[MaxN][MaxN];
int arr[MaxN];
int N;

ll rec(int ii, int jj){

    if(ii==jj) return arr[ii];
    auto &ret = dp[ii][jj];
    if(ret!=-1) return ret;
    return ret = max( arr[ii]-rec(ii+1,jj) , arr[jj]-rec(ii,jj-1) );
}

void read(){

    memset(dp, -1, sizeof dp);
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];

}

void solve(){

    read();
    cout<< rec(0,N-1) << "\n";

}

int main(){

//    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
