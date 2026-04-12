#include<iostream>
using namespace std;
int main(){
  char c[100002];
  bool animal[100002];
  int N;
  cin >> N >> c;
  bool init[4][2] = {
    {true,true},{true,false},{false,true},{false,false}
  };
  c[N] = c[0]; c[N+1] = c[1];
  for(int pat = 0; pat<4; pat++){
    animal[0] = init[pat][0];
    animal[1] = init[pat][1];
    for(int a = 2; a <= N+1; a++){
      if(c[a-1] == 'o'){
         if(animal[a-1]) animal[a] = animal[a-2];
         else animal[a] = !animal[a-2];
      }
      else{
         if(animal[a-1]) animal[a] = !animal[a-2];
         else animal[a] = animal[a-2];
      }
    }
    
    if(animal[0] == animal[N] && animal[1] == animal[N+1]){
      for(int a = 0; a < N; a++){
        cout << ((animal[a]) ? 'S':'W');
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
