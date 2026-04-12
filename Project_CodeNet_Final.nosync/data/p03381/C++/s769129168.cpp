#include <bits/stdc++.h>
using namespace std;

int su[200001];
int su2[200001];

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    su[i] = su2[i] = x;
  }
  sort(su2, su2+n);
  for(int i=0;i<n;i++){
    if(su[i] < su2[n/2]) printf("%d\n", su2[n/2]);
    else printf("%d\n", su2[n/2-1]);
  }
}
