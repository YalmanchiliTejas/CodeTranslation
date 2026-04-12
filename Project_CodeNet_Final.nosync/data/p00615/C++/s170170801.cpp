#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int> num;
  int n,m,l,i;
  int max;

  while(1){
    cin>>n>>m;
    if(n==0&&m==0) break;
    max=0;
    
    num.push_back(0);
    
    for(i=0;i<n;i++){
      cin>>l;
      num.push_back(l);
    }
    for(i=0;i<m;i++){
      cin>>l;
      num.push_back(l);
    }
    sort(num.begin(),num.end());

    for(i=0;i<(int)num.size()-1;i++)
      if(num[i+1]-num[i]>max) max=num[i+1]-num[i];
    
    printf("%d\n",max);
    num.clear();
    max=0;
  }
  return 0;
}