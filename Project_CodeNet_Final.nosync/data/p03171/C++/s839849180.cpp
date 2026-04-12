#pragma GCC optimize("Ofast")
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
#include <map>
#include<tuple>
using namespace std;
#define INF 1LL<<62
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
//typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

ll dp[3100][3100];
ll a[3100];
int N;

ll dfs(int r,int l){
    if(dp[r][l]!=INF) return dp[r][l]; 
    ll temp=0;
    if( (N-(l-r+1))%2==0 ){
        if(r==l) temp=a[r];
        else temp=max(dfs(r+1,l)+a[r],dfs(r,l-1)+a[l]);
    }else{
        if(r==l) temp=0;
        else temp=min(dfs(r+1,l),dfs(r,l-1));
    }
    return dp[r][l]=temp;
}

int main(){
    for(int i=0;i<3100;i++){
        for(int j=0;j<3100;j++) dp[i][j]=INF;
    }
    cin>>N;
    ll sum=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        sum+=a[i];
    } 

    cout<<-sum+2*dfs(1,N)<<endl;

}