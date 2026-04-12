#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,n;
  cin >> n >> a;
  int rslt = 1;
  for(int i=1;i<n;i++)
  {
    cin >> b;
    if(a<=b){rslt++;a=b;}
  }
  cout << rslt;
}