#include<iostream>
#include<vector>
#include<algorithm>

#define N 2<<10

using namespace std;

int main(){

  int data[31], num, ac, team[N];
  char trash;
  vector<int> V;

  for(int i = 0; i < 31; i++) data[i] = 0;
  for(int i = 0; i < N; i++) team[i] = 0;

  while(cin >> num >> trash >> ac){
    if(num == 0 && ac == 0) break;

    if(data[ac] == 0) V.push_back(ac);

    data[ac] = 1;
    team[num] = ac;
  }

  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());

  while(cin >> num){

    for(int i = 0; i < V.size(); i++){

      if(V[i] == team[num]) cout << i+1 << endl;

    }
  }
  return 0;
}
    
    