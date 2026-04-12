#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 100010
int n;
bool t[N];
unordered_set<int> v[N];
unordered_set<int>::iterator it;
queue<int> Q;
void BFS(int x){
  if(v[x].size()==0)return;
  int to=*v[x].begin();
  t[to]=false;
  t[x]=false;
  //cout<<"%"<<x<<" "<<to<<endl;
  for(it=v[x].begin();it!=v[x].end();it++){
    v[*it].erase(x);
  }
  for(it=v[to].begin();it!=v[to].end();it++){
    v[*it].erase(to);
    if(v[*it].size()==1)Q.push(*it);
  }
}
int main(){
  cin>>n;
  lol(i,n-1){
    int a,b;cin>>a>>b;
    a--,b--;
    v[a].insert(b);
    v[b].insert(a);
  }
  lol(i,n)t[i]=true;
  lol(i,n)if(v[i].size()==1)Q.push(i);
  while(!Q.empty()){
    int x=Q.front();
    Q.pop();
    BFS(x);
  }
  int sum=0;
  lol(i,n)sum+=t[i];
  cout<<(sum>0?"First":"Second")<<endl;
  return 0;
}
