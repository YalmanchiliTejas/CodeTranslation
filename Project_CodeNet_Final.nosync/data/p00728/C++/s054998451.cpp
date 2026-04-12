#include <iostream>

using namespace std;

main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) break;

    int in[100];
    int sum=0;
    for(int i=0;i<n;i++){
      cin >> in[i];
      sum+=in[i];
    }

    int min=100000;
    int max=-1;
    for(int i=0;i<n;i++){
      if(min>in[i]) min=in[i];
      if(max<in[i]) max=in[i];
    }
    sum-=min;
    sum-=max;
    printf("%d\n", (int)(sum/(n-2)));
  }
  return 0;
}