#include<iostream>
#include<map>
using namespace std;

map<string, int> NEWS = {
  {"North",1},
  {"East",2},
  {"South",3},
  {"West",4},
  {"Right",5},
  {"Left",6}};

class dice{
public:
  int me[6];
  void North();
  void East();
  void South();
  void West();
  void Right();
  void Left();
  int Rotate(string str);
  dice();
};
void dice::North(){
  swap(me[0],me[2]);
  swap(me[2],me[5]);
  swap(me[5],me[4]);
}
void dice::East(){
  swap(me[3],me[2]);
  swap(me[2],me[1]);
  swap(me[1],me[4]);
}
void dice::South(){
  swap(me[5],me[2]);
  swap(me[2],me[0]);
  swap(me[0],me[4]);
}
void dice::West(){
  swap(me[1],me[2]);
  swap(me[2],me[3]);
  swap(me[3],me[4]);
}
void dice::Right(){
  swap(me[0],me[1]);
  swap(me[1],me[5]);
  swap(me[5],me[3]);
}
void dice::Left(){
  swap(me[0],me[3]);
  swap(me[3],me[5]);
  swap(me[5],me[1]);
}

int dice::Rotate(string str){
  int &i = NEWS[str];
  if(i == 0){return me[2];}
  switch(NEWS[str]){
  case 1: North(); break;
  case 2: East();  break;
  case 3: South(); break;
  case 4: West();  break;
  case 5: Right(); break;
  case 6: Left();  break;
  default: break;
  }
  return me[2];
}
dice::dice(){
  me[0] = 5;
  me[1] = 4;
  me[2] = 1;
  me[3] = 3;
  me[4] = 6;
  me[5] = 2;
}

int main(){
  while(true){
    int n;
    string str;
    dice d;
    int sum = 1;
    cin >> n;
    if(0 == n) { break; }
    for(int i = 0; i < n; i++){
      cin >> str;
      sum += d.Rotate(str);
    }
    cout << sum << endl;
  }
  return 0;
}