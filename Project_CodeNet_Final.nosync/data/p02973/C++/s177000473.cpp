//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>
using namespace std;typedef long long ll;

#define pb push_back
#define endl "\n";
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
const int maxn=1e5+5;const int mod=1e9+7;const int inf=1e9;const int del=728729;int n , a[maxn] , last[maxn]; ll ans;int main(){migmig ;cin>>n ; for(int i = 1 ; i <= n ; i ++){cin>>a[i] ;}int ans = 0 ; fill(last,last+maxn,-inf) ; for(int i = 1 ; i <= n ; i++){int l = 1 , r = maxn ;while(r - l > 1){int mid = (l + r) / 2 ; if(last[mid] >= a[i]) l = mid ; else r = mid ; }ans = max(ans , l+1) ;last[l+1] = max(last[l+1] , a[i]) ; }cout<<ans-1;}

