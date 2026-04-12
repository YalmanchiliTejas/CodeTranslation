#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
char s[N];
int a[N];
int f[N][2][4];
int dfs(int pos,int up,int k){
    if(k<0) return 0;
    if(pos==-1) return k==0;
    int &ans = f[pos][up][k];
    if(ans!=-1) return ans;
    ans = 0;
    for(int i=0;i<=(up?a[pos]:9);i++){
        ans += dfs(pos-1,up&&i==a[pos],k-(!!i));
    }
    return ans;
}
int main(){
    int k; cin>>s>>k;
    int len = strlen(s);
    for(int i=0;i<len;i++) a[i] = s[len-i-1]-'0';
//    for(int i=0;i<len;i++) cout<<a[i]<<' '; cout<<endl;
    memset(f,-1,sizeof(f));
    cout<<dfs(len-1,1,k)<<endl;
}
