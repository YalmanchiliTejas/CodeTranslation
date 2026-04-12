#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define LL long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int INF=1e9+7;
//
int N;
VE D;
bool DFS(int now,int nok){
  if(nok<10){
    return false;
  }else if(now==N-1){
    return true;
  }
  now++;
  nok-=10;
  if(DFS(now,max(D[now],nok))){
    return true;
  }
  return false;
}
int main(){
  cin>>N;
  FOR(i,0,N){
    int d;
    cin>>d;
    D.PB(d);
  }
  if(!DFS(0,D[0])){
    cout<<"no"<<endl;
    return 0;
  }
  reverse(D.begin(),D.end());
  if(!DFS(0,D[0])){
    cout<<"no"<<endl;
  }else{
    cout<<"yes"<<endl;
  }
  return 0;
}
