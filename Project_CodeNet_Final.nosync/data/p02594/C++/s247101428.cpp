#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fip ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define reptUsual(b) for(i=0; i<b; ++i)
#define rept(i,a,b) for(i=a; i<b; ++i)
#define pb(a) push_back(a)
#define newln cout<<"\n"
#define bigPrime 1000000007
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll , ll> pll;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  new_data_set;
// continue // break // greater // string // length // while //iterator //first //second //size //begin //end
 
/*
void funct(int *dp,int *ar, int n){
    if( dp[n]!=0) return;
    else{
        int res=1;
        for(int i=n-1;i>=0;i--){
            
            if(ar[n]>ar[i]){
                funct(dp,ar,i);
                res=max(res, dp[i]+1);
            }
 
        }
        dp[n]=res;
    }
}

bool cmp(pair<int, int>& a, 
         pair<int, int>& b) 
{ 
    return a.second > b.second; 
}
*/

void dfs2(vector <vi> &v, vector<vi> &vis, vi &ancestors, int a,int b){

    
}


int dfs(vector <vi> &v, int n, vector<vi> &vis, vi &ancestors){
    int i,cnt=0;
    ancestors.pb(n);
    reptUsual(v[n].size()){
        if(vis[n][v[n][i]]==0)  {
            for(int j=0;j<ancestors.size();j++) if(ancestors[j]==v[n][i]){ dfs2(v,vis,ancestors,n,v[n][i]);}
            for(int j=0;j<ancestors.size();j++) vis[ancestors[j]][v[n][i]]=1;
            cnt+=dfs(v,v[n][i],vis,ancestors)+1;            
            
            }
    }
    return cnt;

}


int main()
{
    fip;
    int t;
    cin>>t;
    if(t>=30) cout<<"Yes";
    else cout<<"No";

    return 0;
}