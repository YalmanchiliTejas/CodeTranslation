#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n,arr[200001];
map<pair<pair<int,int>,bool>,long long> memo;
long long dp(int index,int taken,bool prevtake){
    if (index>n){
        if (taken==n/2) return 0;
        return -1e15;
    }
    long long maxtake=taken;
    maxtake+=(n-index+2)/2;
    if (maxtake<n/2) return -1e15;
    if (memo.find(mp(mp(index,taken),prevtake))!=memo.end()){
        return memo[mp(mp(index,taken),prevtake)];
    }
    long long res=0;
    res=dp(index+1,taken,false);
    if (!prevtake){
        res=max(res,dp(index+1,taken+1,true)+arr[index]);
    }
    return memo[mp(mp(index,taken),prevtake)]=res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>arr[i];
    }
    /*
    for (int i=1;i<=n;i++){
        pre[i][0]=pre[i-1][0];
        pre[i][1]=pre[i-1][1];
        pre[i][i%2]+=arr[i];
    }
    for (int i=n;i>=1;i--){
        post[i][0]=post[i+1][0];
        post[i][1]=post[i+1][1];
        post[i][i%2]+=arr[i];
    }
    if (n%2==0){
        cout<<max(pre[n][0],pre[n][1]);
        return 0;
    }
    ans=pre[n][0];
    for (int i=1;i<=n;i++){
        //dont take i
        if (i%2==1){
            long long one=0,two=0;
            one=max(pre[i-1][0],pre[i-1][1]);
            two=max(pre[n][0]-pre[i][0],pre[n][1]-pre[n][1]);
            ans=max(ans,one+two);
        }
        else {
            long long one=0,two=0;
            one=pre[i-1][1];
            one+=pre[n][0]-pre[i][0];
            two=pre[i-1][0];
            two+=pre[n][1]-pre[i][1];
            ans=max(ans,one);
            ans=max(ans,two);
        }
    }
    */
    cout<<dp(1,0,false);
}