#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define FI first
#define SE second
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<long long>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
int MOD=1e9+7;
int INF=1e9+7;
//
int H,W;
char hoge;
int cnt;
//
int main(){
  cin>>H>>W;
  FOR(i,0,H){
    FOR(j,0,W){
      cin>>hoge;
      if(hoge=='#'){
        cnt++;
      }
    }
  }
  if(cnt==H+W-1){
    cout<<"Possible"<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }
  return 0;
}
