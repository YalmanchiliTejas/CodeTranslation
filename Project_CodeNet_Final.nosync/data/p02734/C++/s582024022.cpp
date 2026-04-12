#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include<string>
#include<cstring>
#include<complex>
#include<cmath>
using namespace std;
#define rep(i, n)   for(int i = 0; i < (int)(n); i++)
#define rrp(i, n)   for(int i = ((int)(n)); i >=0; i--)
#define mpp(i,j,k)  make_pair((int)(i),make_pair((int)(j),(int)(k)))
typedef pair<int,pair<int,int > > ppp;
typedef pair<int,int> pp;
typedef vector<int> vi;
typedef vector<vi>  vvi;

int main(){
vvi d(3001,vi(3001,0));
int a[3001];
int n,s;
cin>>n>>s;
rep(i,n)cin>>a[i];
long long ans=0;
long long mod=998244353;
rep(i,n)d[i][0]=1;
rep(i,n)for(int j=s;j>=0;j--){
d[i+1][j]+=d[i][j];
d[i+1][j]%=mod;
if((j+a[i])<=s){
    
    d[i][j+a[i]]+=d[i][j];
    d[i][j+a[i]]%=mod;
    d[i+1][j+a[i]]=d[i][j+a[i]];
}
}
rep(i,n)ans+=d[i][s],ans%=mod;
cout<<ans<<endl;
  return 0;
}
