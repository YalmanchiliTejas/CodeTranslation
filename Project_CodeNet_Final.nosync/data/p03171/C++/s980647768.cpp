#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define forN(i, n) for(int i = 1; i <=n ; ++i)
#define endl "\n"
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const int N = 3005;
ll n , A[N],DP[N][N];
/*
ll taro = max(calc(i+1,j)+A[i],calc(i,j-1)+A[j]);
    ll jaro = min(calc(i+1,j)+A[i],calc(i,j-1)+A[j]);
*/
ll calc(int i , int j){
    if(i == j)return A[i];
    if(DP[i][j]!=-1)return DP[i][j];
    ll left = A[i] - calc(i+1,j);
    ll right = A[j] - calc(i,j-1);
    return DP[i][j] = max(left,right);

}

int main(){
    fastIO;
    cin>>n;
    forN(i,n)cin>>A[i];
    memset(DP,-1,sizeof DP);
    cout<<calc(1,n);
}

