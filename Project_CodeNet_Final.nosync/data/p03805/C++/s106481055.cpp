#include <bits/stdc++.h>
using namespace std;

bool isPassed(int n, int s){
  return (s >> n-1 >> 4) & 1;
}

int addPassed(int n, int s){
  int r = s | (1 << n-1 << 4);
  return (r & 0b111111110000) | n;
}

int getCurrent(int s){
  return s & 0b000000001111;
}

vector<int> moveNext(vector<int> a, vector<int> b, vector<int> state){
  vector<int> nextState;  
  for (int i=0;i<state.size();i++){
    int c = getCurrent(state[i]);
    for (int j=0;j<a.size();j++){
      if (a[j]==c && !isPassed(b[j], state[i])){
        nextState.push_back(addPassed(b[j], state[i]));
      }
    }
    for (int j=0;j<b.size();j++){
      if (b[j]==c && !isPassed(a[j], state[i])){
        nextState.push_back(addPassed(a[j], state[i]));
      }
    }
  }
  return nextState;
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
  }

  vector<int> state(1);
  state[0]=addPassed(1, 0);
  for (int i=1;i<n;i++){
    state = moveNext(a,b,state);
  }
  
  cout << state.size() << endl;
  
  return 0;
}
