#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<map>
#include<tuple>
using namespace std;
#define INF 1100000000000
#define MAX 1100000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

ll dp[3100][3100],a[3100];
bool flag[3100][3100];

ll f(int l,int r){
    if(flag[l][r]) return dp[l][r];
    flag[l][r]=true;
    if(l==r) return dp[l][r]=a[l];
    return dp[l][r]=max(a[l]-f(l+1,r),a[r]-f(l,r-1));
}

int main(){
    int N; cin>>N;
    for(int i=0;i<3100;i++){
        for(int j=0;j<3100;j++){
            flag[i][j]=false;
        }
    }
    for(int i=0;i<N;i++) cin>>a[i];
    ll ans=f(0,N-1);
    cout<<ans<<endl;
}

