#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string rep;
  string sw = "NN";
  for (int i=2; i<N; i++) {
    sw += "N";
  }
  cin >> rep;
  vector<int> vsw(N);
  int repl = -1;
  if (rep[N-1] == 'o') {
    repl += 2;
  }
  
  int repl2 = -1;
  if (rep[0] == 'o') {
    repl2 += 2;
  }
  
  bool can = false;
  
  vsw[0] = 1;
  vsw[1] = 1;
  for(int i=0; i<N-2; i++) {
    if (rep[i+1] == 'o') {
      vsw[i+2] = vsw[i] * vsw[i+1];
    }
    else {
      vsw[i+2] = vsw[i] * vsw[i+1] * -1;
    }
  }
  if (vsw[N-2] * vsw[N-1] * vsw[0] * repl == 1
     && vsw[N-1] * vsw[0] * vsw[1] * repl2 == 1) {
    can = true;
    for (int i=0; i<N; i++) {
      if (vsw[i] == 1) {
        sw[i] = 'S';
      }
      else {
        sw[i] = 'W';
      }
    }
  }
  
  vsw[0] = -1;
  vsw[1] = -1;
  for(int i=0; i<N-2; i++) {
    if (rep[i+1] == 'o') {
      vsw[i+2] = vsw[i] * vsw[i+1];
    }
    else {
      vsw[i+2] = vsw[i] * vsw[i+1] * -1;
    }
  }
  if (vsw[N-2] * vsw[N-1] * vsw[0] * repl == 1
     && vsw[N-1] * vsw[0] * vsw[1] * repl2 == 1) {
    can = true;
    for (int i=0; i<N; i++) {
      if (vsw[i] == 1) {
        sw[i] = 'S';
      }
      else {
        sw[i] = 'W';
      }
    }
  }
  
  vsw[0] = 1;
  vsw[1] = -1;
  for(int i=0; i<N-2; i++) {
    if (rep[i+1] == 'o') {
      vsw[i+2] = vsw[i] * vsw[i+1];
    }
    else {
      vsw[i+2] = vsw[i] * vsw[i+1] * -1;
    }
  }
  if (vsw[N-2] * vsw[N-1] * vsw[0] * repl == 1
     && vsw[N-1] * vsw[0] * vsw[1] * repl2 == 1) {
    can = true;
    for (int i=0; i<N; i++) {
      if (vsw[i] == 1) {
        sw[i] = 'S';
      }
      else {
        sw[i] = 'W';
      }
    }
  }
  
  vsw[0] = -1;
  vsw[1] = 1;
  for(int i=0; i<N-2; i++) {
    if (rep[i+1] == 'o') {
      vsw[i+2] = vsw[i] * vsw[i+1];
    }
    else {
      vsw[i+2] = vsw[i] * vsw[i+1] * -1;
    }
  }
  if (vsw[N-2] * vsw[N-1] * vsw[0] * repl == 1
     && vsw[N-1] * vsw[0] * vsw[1] * repl2 == 1) {
    can = true;
    for (int i=0; i<N; i++) {
      if (vsw[i] == 1) {
        sw[i] = 'S';
      }
      else {
        sw[i] = 'W';
      }
    }
  }
  if (can) {
    cout << sw << endl;
  }
  else {
    cout << -1 << endl;
  }
}
