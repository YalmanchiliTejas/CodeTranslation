#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
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
  int S,T;
  scanf("%d %d",&S,&T);
  printf("%.9f\n",(double)S*T/(S+T));
  return 0;
}
