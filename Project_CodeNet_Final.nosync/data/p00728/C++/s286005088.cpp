#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int n;
  while(scanf("%d",&n),n){
    vector<int> v(n);
    for(int i=0;i<n;i++){
      int tmp;
      scanf("%d",&tmp);
      v[i]=tmp;
    }
    double ans=0;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size()-1;i++){
      ans+=(double)v[i];
    }
    printf("%d\n",(int)(ans/(v.size()-2)));
  }
  return 0;
}