#include<bits/stdc++.h>
using namespace std;

int main(){
  long n,x,kekka = 0;
  cin >> n >> x;
  long d = x;
  for(long i = 0;i < n+1;i++){
    long c = 1;
    for(long j = 0;j < n - i;j++){
      c *= 2;
    }
    long centr = 2*c - 1;
    if(centr == d){
      kekka += c;
      //cout << 1 << endl;
      break;
    }
    else if(centr > d){
      d -= 1;
      //cout << 2 << endl;
    }
    else if(centr < d){
      kekka += c;
      //cout << 3 << endl;
      d -= 2*c - 1;
    }
  }
  cout << kekka << endl;
}