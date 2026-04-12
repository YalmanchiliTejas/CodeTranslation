#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x;
  cin >> N;
  x=800*N;
  if(N<15)
    cout << x << endl;
  else if(N<30)
    cout << x-200 << endl;
  else if(N<45)
    cout << x-400 << endl;
  else if(N<60)
    cout << x-600 << endl;
  else if(N<75)
    cout << x-800 << endl;
  else if (N<90)
    cout << x-1000 << endl;
  else
    cout << x-1200 << endl;
}