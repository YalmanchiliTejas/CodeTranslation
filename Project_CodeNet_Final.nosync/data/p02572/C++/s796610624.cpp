#include <iostream>
using namespace std;

int main(void){
  int n;
  cin>>n;
  long int a[n];
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  long long int sum_1=0,sum_2=0;
  for (int i = 0; i < n; i++)
  {
    sum_1+=a[i];
  }
  sum_1%=1000000007;
  for (int i = 0; i < n; i++)
  {
    sum_1-=a[i];
    if(sum_1<0)sum_1+=1000000007;
    sum_2=(sum_2+a[i]*sum_1)%1000000007;
  }
  cout<<sum_2<<endl;
  return 0;
}