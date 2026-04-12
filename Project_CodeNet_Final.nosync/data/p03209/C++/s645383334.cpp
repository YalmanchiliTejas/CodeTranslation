#include <bits/stdc++.h>
 
using namespace std;

long long burg(long long  N,long long X){
  long long length,point;
  if(X<=0) return 0;
  else if(N==0) return 1;
  length = 4*pow(2,N)-3;
  point = length/2 + 1;
  if(point > X) return burg(N-1,X-1);
  else if(point == X) return (point-1)/2+1;
  else return (point-1)/2+1+burg(N-1,X-point);
}

int main(int argc,char* argv[]){
  long long N,X;
  cin >> N >> X;
  cout << burg(N,X) << endl;

  return 0;
}
