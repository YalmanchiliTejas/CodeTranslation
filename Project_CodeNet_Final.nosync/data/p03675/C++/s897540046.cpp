#include<bits/stdc++.h>
using namespace std;
//define
#define int long long
#define rep(x,y) for(int i=x;i<y;i++)
#define REP(x,y) for(int j=x;j<y;j++)
#define Rep(x,y) for(int k=x;k<y;k++)
#define str string
//vectordefine
#define vint vector<int>
#define vvint vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vool vector<bool>
#define vtr vector<str>
#define vvtr vector<vector<str>>
//queuedefine
#define qint queue<int>
#define qtr queue<string>
#define qc queue<char>
//pairdefine
#define pint pair<int,int>
#define pic pair<int,char>
#define pci pair<char,int>
#define pis pair<int,str>
#define psi pair<str,int>
#define pcc pair<char,char>
#define pss pair<str,str>
#define mp make_pair
//mapdefine
#define mint map<int,int>
#define mic map<int,char>
#define mci map<char,int>
#define mis map<int,str>
#define msi map<str,int>
#define pb() push_back()
#define all(x) x.begin(),x.end()
#define elif else if
//function
str shizuku(char,char);
//UnionFind
struct UnionFind{
  vint par;
  UnionFind(int N):par(N){
    rep(0,N)par[i]=i;
  }
  int root(int x){
    if(par[x]==x)return x;
    return par[x]=root(par[x]);
  }
  void unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if(rx==ry)return;
    par[rx]=ry;
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
};
//binary_search

//main
signed main(){
    int N=0,M,X,count=0,count2=0;
    double d,D;
    int alph='A'-'a';
    char op,Ch;
    str S,T;
    cin>>N;
    int a[N]={};
    rep(0,N)cin>>a[i];
    if(N%2==0){
      for(int i=N;i>0;i-=2)cout<<a[i-1]<<" ";
      for(int i=0;i<N;i+=2)cout<<a[i]<<" ";
    }
    elif(N%2==1){
      for(int i=N;i>0;i-=2)cout<<a[i-1]<<" ";
      for(int i=1;i<N;i+=2)cout<<a[i]<<" ";
    }
    cout<<endl;
}
