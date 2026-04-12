#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n,s,p;
int arr[3001];
long long memo[3001][3001][2],ans;
long long dp(int index,int left,bool take){
    if (left==0){
        return n-(index-1)+1;
    }
    if (left<0 || index>n) return 0;
    if (memo[index][left][take]!=-1){
        return memo[index][left][take];
    }
    long long one=dp(index+1,left,take);
    long long two=dp(index+1,left-arr[index],true);
    if (!take){
        //cout<<index<<' '<<two<<'\n';
        ans+=two*index;
        ans%=p;
    }
    return memo[index][left][take]=(one+two)%p;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (int i=1;i<=n;i++){
        cin>>arr[i];
    }
    memset(memo,-1,sizeof(memo));
    p=998244353;
    dp(1,s,false);
    cout<<ans;
}