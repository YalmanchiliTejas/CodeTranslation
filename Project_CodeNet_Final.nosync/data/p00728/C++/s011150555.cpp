#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,score[100],i,sum,k=1;
  int max,min;

  while(k<=20){
    sum=0;
    max=0;
    min=1000;
    
    cin >> n;
    if(n==0)break;
    for(i=0;i<n;i++){
      cin >> score[i];
      if(max<score[i])max=score[i];
      if(score[i]<min)min=score[i];
      sum+=score[i];
    }
    sum-=(max+min);
    n-=2;
    cout<<(sum/n)<<endl;
    k++;
  }
  return 0;
}
