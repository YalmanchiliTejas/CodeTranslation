using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(void) {
  int n,m;
  cin>>n>>m;
  int i;
  int path[10][10]={};
  for (int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    path[a][b]++;
    path[b][a]++;
  }

  vector<int> v;
  for (int i = 0; i < n; i++){
    v.push_back(i);
  }
 
  int ans=0;
  do{
    if(v[0]!=0)break;
    for (i = 0; i < n-1; i++){
      if(path[v[i]][v[i+1]]==0)break;
    }
    if(i==n-1)ans++;
  }while(next_permutation(all(v)));
 
  cout<<ans<<endl;
}
