
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
bool edge[N][N];

int ans=0;

int main(){
    cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        edge[a][b]=edge[b][a]=true;
    }
    vector<int>perm;
    perm.push_back(1);
    rep(i,1,n-1)perm.push_back(i+1);
    
    do{
        bool flag=true;
        rep(i,0,n-2){
            int a=perm[i],b=perm[i+1];
            if(!edge[a][b]){
                flag=false;
                break;
            }
        }
        if(flag)ans++;
    }while(next_permutation(perm.begin()+1,perm.end()));
    
    cout<<ans<<endl;
    
    return 0;
}
