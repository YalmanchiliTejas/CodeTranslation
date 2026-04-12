#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define TT pair<long long, long long>
#define ordered_set tree<TT, null_type, less<TT>, rb_tree_tag, tree_order_statistics_node_update>
#define fo(i,n)   for(i=0;i<n;i++)
#define mem(a,i) memset(a,i,sizeof(a))
#define pb push_back
#define mp make_pair
#define For(m) for(auto it = m.begin();it!=m.end();it++)
#define fi first
#define se second
typedef long long ll;
typedef long double mytype;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //priority_queue <int, vector<int>, greater<int> > pq;
    //cout << fixed << setprecision(9) <<ans<<endl;
    //ordered_set os;//os.order_of_key();//os.find_by_order();
    ll l,r,count,n,m,sum=0,ans=0,i,j,k,tt,t,x,y,z,c,a[200005]={},b[200005]={};
    string ss;
    set<ll> s;
    vector<ll> v;
    map<ll,ll> ma;
    ll dp[3000][3000][2]={};
    cin>>n;
    fo(i,n){
        cin>>a[i];
        dp[i][i][0]=a[i];
    }
    for(i=1;i<n;i++){
        for(j=0;j<(n-i);j++){
            if((a[j]+dp[j+1][j+i][1])>=(a[j+i]+dp[j][j+i-1][1])){
                dp[j][j+i][0]=a[j]+dp[j+1][j+i][1];
                dp[j][j+i][1]=dp[j+1][j+i][0];
            }
            else{
                dp[j][j+i][0]=a[j+i]+dp[j][j+i-1][1];
                dp[j][j+i][1]=dp[j][j+i-1][0];
            }
        }
    }
    cout<<dp[0][n-1][0]-dp[0][n-1][1]<<endl;
}