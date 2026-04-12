#include<bits/stdc++.h>
using namespace std;
int n;
int data[300000];
int go(int now,int want){
  if(now==0&&data[now]>=want)
    return 1;
  if(now==0&&data[now]<want)
    return 0;
  if(data[now]>=want)
    want=10;
  else
    want+=10;
  return go(now-1,want);
}
int come(int now,int want){
  if(now==n-1&&data[now]>=want)
    return 1;
  if(now==n-1&&data[now]<want)
    return 0;
  if(data[now]>=want)
    want=10;
  else
    want+=10;
  return come(now+1,want);
}
int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&data[i]);
  int f=0;
  f+=go(n-2,10);
  f+=come(1,10);
  if(f==2)
    printf("yes\n");
  else
    printf("no\n");
  return 0;
}