#include <iostream>
using namespace std;

long long a[51];
long long p[51];

long long f(int N, long long X) {
  if(X==1) return ((N==0)? 1: 0);
  else if(1<X && X<=1+a[N-1]) return f(N-1,X-1);
  else if(X==2+a[N-1]) return p[N-1]+1;
  else if(2+a[N-1]<X && X<=2+2*a[N-1]) return p[N-1]+1+f(N-1,X-2-a[N-1]);
  else return 2*p[N-1]+1;

}

int main() {
  int N;
  long long X;
  cin >> N >> X;

  a[0]=1;
  p[0]=1;
  for(int i=1; i<51; i++) {
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }

  cout << f(N, X) << endl;
}
