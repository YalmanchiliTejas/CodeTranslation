#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
typedef struct aaaaa{
  int x,y,t;
}Grid;
using namespace std;
ll memo[1000]={};
ll num;
ll rec(int de){
  if(de==0)return 1;
  if(memo[de]!=0)return memo[de];
  return (memo[de]=2*rec(de-1)+3);
}
ll pa[100]={};
ll n,x;

ll dfs(int de){
  //cout<<num/2<<endl;
  if(num<=0)return 0;
  if(num/2>=x){
    num/=2;
    num--;
    x--;
    return dfs(de-1);
  }else if(num/2+2<=x){
    num/=2;
    num--;
    x-=num+2;
    //  cout<<pa[de]<<endl;
    return dfs(de-1)+pa[de]+1;
  }else{
    //cout<<"!"<<endl;
    return pa[de]+1;
  }
}

int main(){
  cin>>n>>x;
  //memo[0]="P";
  num=rec(n);
  for(int i=1;i<=n;i++)
   (pa[i]=pa[i-1]*2+1);
  cout<<dfs(n)<<endl;
  return 0;
}