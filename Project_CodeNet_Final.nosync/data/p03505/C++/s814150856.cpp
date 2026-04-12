#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<int>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define MOD 1000000007
#define INF 1000000007
#define PI 3.14159265358979323846
using namespace std;
//
int main(){
  long long K,A,B;
  cin>>K>>A>>B;
  if(K<=0){
    cout<<"0"<<endl;
  }else{
    if(A<K&&A<=B){
      cout<<"-1"<<endl;
    }else if(K<=A){
      cout<<"1"<<endl;
    }else{
      K-=A;
      cout<<(K+(A-B)-1)/(A-B)*2+1<<endl;
    }
  }
  return 0;
}
