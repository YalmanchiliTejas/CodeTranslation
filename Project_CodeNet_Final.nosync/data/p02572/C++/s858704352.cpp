#include <iostream>

using namespace std;

int main(){
  int n;
  const int v=1000000007;
  cin >> n;
  long long Arr[n],sum=0,tempsum=0,arrsum=0;
  for(int z=0;z<n;z++){
    cin >> Arr[z];
  }
  for(int x=0;x<n;x++){
    arrsum+=Arr[x];
    arrsum%=v;
  }
  for(int x=0;x<n;x++){
    arrsum=(arrsum-Arr[x]+v)%v;
    tempsum=(Arr[x])*(arrsum);
    tempsum%=v;
    sum+=tempsum;
    sum%=v;
  }
  cout << sum;
}