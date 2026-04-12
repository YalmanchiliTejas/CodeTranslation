#include<bits/stdc++.h>
using namespace std;
/*
int main(){
  int n;
  scanf("%d",&n);
  char a,b;
  scanf("%c",&a);
  for(int i=0;i<n-1;i++){
    scanf("%c",&b);
     printf("%c\n",b);
    if(a == 'T' && b == 'F')a = 'F';
    else a = 'T';
    printf("%c\n",b);
  }
  printf("\n%c\n",a);
  return 0;
  */
int main(){
  int n;
  char a,b;
  scanf("%d\n",&n);
  scanf("%c",&a);
  for(int i=0;i<n-1;i++){
    scanf(" %c",&b);
    //  printf("%d %c\n",i,b);
    if(a == 'T' && b == 'F'){
      a = 'F';
    }else{
      a = 'T';
    }
  }
  printf("%c\n",a);
  return 0;
}

