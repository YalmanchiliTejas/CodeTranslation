#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int main(){
  int n; scanf("%d", &n);
  int x[500000];
  vector<pii> xyz;
  for(int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    xyz.push_back(make_pair(x[i], i));
  }
  sort(xyz.begin(), xyz.end());
  int mid1 = xyz[n/2-1].first;
  int mid2 = xyz[n/2].first;
  //int flag[500000];
  /*if(mid1 == mid2){
    for(int i = 0; i < n; i++) printf("%d\n", mid1);
  }*/
  for(int i = 0; i < n; i++){
    if(x[i] < mid2) printf("%d\n", mid2);
    else printf("%d\n", mid1);
  }
  return 0;
}
  