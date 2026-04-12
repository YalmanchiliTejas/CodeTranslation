#include<iostream>

using namespace std;

const int MAX = 3000;

int N,T,E;

bool solve(int num){
  for(int i = 1; num*i <= MAX; i++)
    if(T-E <= num*i && num*i <= T+E)
      return true;
 
  return false;
}

int main(){

  cin >> N >> T >> E;
  for(int i = 0; i < N; i++){
    int in;
    cin >> in;
    if(solve(in)){
      cout << i+1 << endl;
      break;
    }
    if(i == N-1) cout << "-1" << endl;
  }
  
  return 0;
}