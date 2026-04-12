#include<iostream>
#include <algorithm>
using namespace std;
long long eat_burger(int n, long long x)
{
  if(n==0){
    if(x==0)
      return 0;
    else
      return 1;
  }
  long long c=((long long)1<<(n+1))-1;
  long long p=(long long)1<<n;
  if(x<=1){
    return 0;
  }else if(x<c){
    return eat_burger(n-1,x-1);
  }else{
    return eat_burger(n-1,x-c)+p;
  }
}
int main()
{
  int n,i;
  long long x,res;
  cin >> n >> x;
  res=eat_burger(n,x);
  cout << res << endl;
  return 0;
}