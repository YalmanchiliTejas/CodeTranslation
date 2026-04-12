#include<iostream>
 
using namespace std;
 
int main(){
  int n;
  scanf("%d",&n);
  int s[n];
  for(int i=0;i<n;i++)
  {
    int temp;
    scanf("%d",&temp);
    s[i]= temp;
  }
  int cnt=1;
  if(n==1)
  {
    cout<< cnt;
    return 0;
  }
  int MAx=s[0];
  for(int i= 1;i<n;i++)
  {
    if(s[i]>=MAx)
    {
      MAx=s[i];
      cnt++;
    }
  }
  cout<< cnt<<endl;
  return 0;
}