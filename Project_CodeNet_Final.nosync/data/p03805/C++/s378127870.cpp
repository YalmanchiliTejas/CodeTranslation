#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<tuple>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=2e5;

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int> > G(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }
    vector<int> num(n);
    for(int i=0;i<n;i++){
        num[i]=i+1;
    }
    int ans=0;
    do{
        bool flag=true;
        for(int i=1;i<n;i++){
            if(G[num[i-1]][num[i]]==0){
                flag=false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(num.begin()+1,num.end()));
    cout<<ans<<endl;
    return 0;
}