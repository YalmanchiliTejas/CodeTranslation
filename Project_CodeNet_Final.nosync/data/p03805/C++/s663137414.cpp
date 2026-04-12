
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


//////////////////////////////////////

#define N 10
int n,m;
vector<int> edge[N];
bool used[N];
int ans=0;
void dfs(int x,int p){
    if(x==n)ans++;
    else{
        for(auto y:edge[p]){
            if(used[y]==true)continue;
            used[y]=true;
            dfs(x+1,y);
            used[y]=false;
        }
    }
}


int main(){
    cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    used[1]=true;
    dfs(1,1);
    
    cout<<ans<<endl;
    
    return 0;
}

