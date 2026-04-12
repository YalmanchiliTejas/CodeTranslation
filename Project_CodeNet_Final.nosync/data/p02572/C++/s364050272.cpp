#include<bits/stdc++.h>
using namespace std;
#define stop exit(0)
#define pb push_back
#define skip continue
#define ll long long
long long a,b,c,d=0,e=0,i,f=0,g=0,j,k=0,l=0,r,m,h[200001],p[200001],df[51];
string t,x,q,s;
double w;
vector<ll>dv[101],v,z;
vector<string>u;
map<string,ll>n;
set<ll>y;
void dfs(ll x){
    df[x]=1;
    for(ll i=0;i<dv[x].size();i++){
        if(dv[x][i]==0){
            dfs(dv[x][i]);
            df[dv[x][i]]=1;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>a;
    h[0]=0;
    for(i=1;i<=a;i++){
        cin>>p[i];
        h[i]=h[i-1]+p[i];
    }
    d=0;
    for(i=a;i>=2;i--){
        d+=(p[i]*(h[i-1]%1000000007));
        d=d%1000000007;
    }
    cout<<d;
}