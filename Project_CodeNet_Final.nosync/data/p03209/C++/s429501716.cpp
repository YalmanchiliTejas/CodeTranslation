#include <iostream>
using namespace std;

long long a(long long N){
  if(N == 0){
    return(1);
  }
  else{
    return(a(N-1)*2+3);
  }
}

long long p(long long N){
  if(N == 0){
    return(1);
  }
  else{
    return(p(N-1)*2+1);
  }
}

long long f(long long N, long long X){
  if(N == 0){
    if(X <= 0){
      return(0);
    }
    else{
      return(1);
    }
  }
  else if(X <= 1 + a(N-1)){
    return (f(N-1, X-1));
  }
  else{
    return (p(N-1) + 1 + f(N-1, X-2-a(N-1)));
  }
}

int main(){
  long long N;
  long long X;
  cin >> N >> X;
  cout << f(N, X) << endl;
}