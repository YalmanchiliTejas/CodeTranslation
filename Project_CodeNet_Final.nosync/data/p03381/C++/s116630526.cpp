#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <fstream>
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
const int MOD=1e9+7;
//
int N;
int X[200000];
int Y[200000];
int main(){
  cin>>N;
  FOR(i,0,N){
    cin>>X[i];
    Y[i]=X[i];
  }
  sort(Y,Y+N);
  int M=Y[N/2-1],MM=Y[N/2];
  FOR(i,0,N){
    if(X[i]<=M){
      cout<<MM<<endl;
    }else{
      cout<<M<<endl;
    }
  }
  return 0;
}
