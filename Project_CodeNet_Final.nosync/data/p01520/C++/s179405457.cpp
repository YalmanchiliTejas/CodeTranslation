#include<bits/stdc++.h>
using namespace std;

int main(){
  const int MAXI = 10001;
  int N, T, E;
  int x[100];
  cin >> N >> T >> E;
  for(int i=0; i < N; i++){
    cin >> x[i];
  }
  for(int i=0; i < N; i++){
    int time;
    for(time=0; time < MAXI; time+=x[i]){
      if(abs(time-T) <= E){
	cout << i+1 << endl;
	return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}