#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define rv(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int M = 120000;
typedef long long ll;
int m,k;
string n;
int C(int a,int b){
    int ret=1;
    fo(i,0,b-1)
        ret = ret*(a-i);
    fo(i,1,b)
        ret /= i;
    return ret;
}
int dfs(int u,int k,int limit) {
    if(k<0) return 0;
    if(u==m) return k==0;
    if (!limit) {
        int ret = C(m-u,k);
        fo(i,1,k) ret*=9;
        return ret;
    }
    if(n[u]=='0') return dfs(u+1,k,limit);
    int ret=dfs(u+1,k-1,limit);
    ret += dfs(u+1,k-1,0) * (n[u]-'1');
    ret += dfs(u+1,k,0);
    return ret;
}
int main(){
    cin>>n>>k;
    m = n.size();
    cout<<dfs(0,k,1)<<endl;
    return 0;
}