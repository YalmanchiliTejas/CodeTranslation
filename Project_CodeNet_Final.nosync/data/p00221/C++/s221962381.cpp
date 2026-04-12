#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  int n,m;
  while(1){
    scanf("%d %d\n",&m,&n);
    if(n==0 && m==0){
      break;
    }
    vector<string> x;
    int end=0,i,j=1,a[1010],l,k;
    string s;
    for(i=1;i<=m;i++){
      a[i]=1;
    }
    x.push_back("a");
    for(i=1;i<=n;i++){
      if(i%15==0){
        x.push_back("FizzBuzz");
      }
      else if(i%3==0){
        x.push_back("Fizz");
      }
      else if(i%5==0){
        x.push_back("Buzz");
      }
      else{
        x.push_back(to_string(i));
      }
    }
    for(i=1;i<=n;i++){
      cin >> s;
      if(end==1){
        continue;
      }
      if(s!=x[i]){
        a[j]=0;
      }
      l=j;
      while(1){
        j++;
        if(j>m){
          j=1;
        }
        if(a[j]==1){
          break;
        }
      }
      int sum=0;
      for(k=1;k<=m;k++){
        if(a[k]==1){
          sum++;
        }
      }
      if(sum==1){
        end=1;
      }
    }
    int b=0;
    for(i=1;i<=m;i++){
      if(a[i]==1){
        if(b==0){
          b=1;
          printf("%d",i);
        }
        else{
          printf(" %d",i);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
