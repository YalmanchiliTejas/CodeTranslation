#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
ll p[100]={1ll},b[100],l[100]={1ll},n,k;///p[i]-->s[i]中有几个p,b[i]-->s[i]中有几个b,l[i]-->s[i]中有几个字母
void init(){
    for(int i=1;i<55;i++){
        p[i] = 2*p[i-1]+1,b[i] = 2*b[i-1]+2;
        l[i] = p[i]+b[i];
    }
}
ll dfs(ll cur,ll len){
    if(!cur)return 1ll;///s[0]='p'
    if(len<=1)return 0ll;///'b'或者空
    if(len == 1+l[cur-1])///'b'+s[i-1]
        return p[cur-1];
    if(len == 2+l[cur-1])///'b'+s[i-1]+'p'
        return p[cur-1]+1;
    if(len == l[cur] || len == l[cur]-1)///'b'+s[i-1]+'p'+s[i-1]或者'b'+s[i-1]+'p'+s[i-1]+'p'
        return p[cur];
    if(len<1+l[cur-1])///'b'+****
        return dfs(cur-1,len-1);
    return p[cur-1]+1+dfs(cur-1,len-l[cur-1]-2);///'b'+s[i-1]+'p'+***
}
int main(){
    init();
    cin>>n>>k;
    cout<<dfs(n,k)<<endl;
    return 0;
}
