#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

ll arr[3005];

ll dp[3005][3005][2];

ll fu(int init,int end,int val){
    if(init>end) return 0;
    if(init==end){ 
        dp[init][init][val]=arr[init];
        if(val==0) return arr[init];
        else return 0;
       
    
    }

    ll tar=0;
    ll x=dp[init][end][val];
    if(x>=0){
        return x;

    }
    if(val==1){
        
        tar=min(fu(init+1,end,0),fu(init,end-1,0));
        dp[init][end][1]=tar;
        return tar;
    }
    if(val==0){
        tar=max(arr[init]+fu(init+1,end,val^1),arr[end]+fu(init,end-1,val^1));
        dp[init][end][0]=tar;
        return tar;
    }
    
}

int main(){
    IOS
    int n;
    cin>>n;
    fo(i,n) cin>>arr[i];
    fo(i,n+1){
        fo(j,n+1){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    ll ans=fu(0,n-1,0);
    ll suum=0;
    fo(i,n) suum+=arr[i];
    cout<<2*ans-suum<<endl;




}