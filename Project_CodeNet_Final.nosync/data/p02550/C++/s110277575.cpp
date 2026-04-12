// Create by JJL
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define int long long
const int N=300010,Mod=1e9+7;
LL n,m,x,tot;
LL nums[N],n2[N];
int vis[N];
signed main(){
    IOS;
    /* START CODE */
    cin>>n>>x>>m;
    int l,r;
    for(int i=1;;++i){
        if(vis[x]) {
            l=vis[x],r=i-1;
            break;
        }
        nums[++tot]=x;
        vis[x]=i;
        x=x*x%m;
       // cout<<x<<endl;
    }
    for(int i=1,j=l;j<=r;++j,++i){
        n2[i]=nums[j];
    }
    for(int i=1;i<=tot;++i) nums[i]+=nums[i-1];
    LL sum=nums[l-1];

    int len=r-l+1;
    n-=l-1;
    for(int i=1;i<=len;++i) n2[i]+=n2[i-1];
    //cout<<sum<<endl;
    sum=sum+n/len*n2[len]+n2[n%len];
    cout<<sum<<endl;
    return 0;
}
