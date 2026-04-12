#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define double long double
using namespace std;
//桁
int kt(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
 }
int lcm(int a,int b){
  int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return d*e/f;
    }
  int gcm(int a,int b){
      int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return f;
  }
int a,b;
vector<int> graph[10];
  int answer=0;
  bool visited[10];
void dfs(int c,int d){
  visited[c]=true;
  d++;
  if(d==a){
    answer++;
  }
  for(int e:graph[c]){
    if(!visited[e])
      dfs(e,d);
  }
  visited[c]=false;
}
signed main(){
  cin>>a>>b;
  rep(i,b){
    int A,B;
    cin>>A>>B;
    graph[B-1].push_back(A-1);
    graph[A-1].push_back(B-1);
  }
  dfs(0,0);
  cout<<answer<<endl;
}
  
