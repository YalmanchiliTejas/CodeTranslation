#include <bits/stdc++.h>
using namespace std;

long long index_2(int x) {
  long long n=1;
  if (x==0) {
    return 1;
  }
  else {
    for (int i=0;i<x;i++) {
      n = n*2;
    }
  return n;
  }
}

int main() {
  int N;
  long long X;
  cin >> N >> X;
  
  long long count=0;
  for (int i=0;i<N;i++) {
    if (X>index_2(N+1-i)-1) {
      if (X==index_2(N+2-i)-3) {
        count += index_2(N-i+1)-1;
        break;
      }
      count += index_2(N-i);
      if (i==N-1) {
        count++;
        break;
      }
      X = X -index_2(N+1-i)+1;
    }
    else if (X<index_2(N+1-i)-1) {
      if (i==N-1 && X==2) {
        count++;
        break;
      }
      X -= 1;
    }
    else if (X==index_2(N+1-i)-1) {
      count += index_2(N-i);
      break;
    }
  }
    
    cout << count << endl;
}