#include<iostream>

using namespace std;

typedef struct{
  char name;
  int sum;
}Store;

int main(){
  Store data[5];
  int am,pm;
  while(cin >> am >> pm && am + pm){
    char now = 'A';
    data[0].name = now;
    data[0].sum = am+pm;
    for(int i = 1; i < 5; i++){
      now++;
      cin >> am >> pm;
      data[i].name = now;
      data[i].sum = am+pm;
    }
    Store max = data[0];
    
    for(int i = 1; i < 5; i++){
      if(data[i].sum > max.sum) max = data[i];
    }

    cout << max.name << " " << max.sum << endl;
  }

  return 0;
}