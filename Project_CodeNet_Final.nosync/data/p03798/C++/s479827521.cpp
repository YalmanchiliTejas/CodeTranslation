#include<iostream>
#include<string>
using namespace std;

int n;
string s;
int fst[4] = {0, 0, 1, 1};
int snd[4] = {0, 1, 0, 1};
int animal[100000];
bool flag;

int main(){
  cin >> n >> s;
  flag = false;
  for(int i = 0; i < 4; i++){
    animal[0] = fst[i];
    animal[1] = snd[i];
    for(int j = 2; j < n; j++){
      if(s[j - 1] == 'o' && animal[j - 1] == 0){
	animal[j] = animal[j - 2];
      }
      else if(s[j - 1] == 'o' && animal[j - 1] == 1){
	animal[j] = (animal[j - 2] + 1) % 2;
      }
      else if(s[j - 1] == 'x' && animal[j - 1] == 0){
	animal[j] = (animal[j - 2] + 1) % 2;
      }
      else{
	animal[j] = animal[j - 2];
      }
    }
    if(s[0] == 'o' && animal[0] == 0){
      if(animal[n - 1] == animal[1]){
	flag = true;
      }
    }
    if(s[0] == 'o' && animal[0] == 1){
      if(animal[n - 1] == (animal[1] + 1) % 2){
	flag = true;
      }
    }
    if(s[0] == 'x' && animal[0] == 0){
      if(animal[n - 1] == (animal[1] + 1) % 2){
	flag = true;
      }
    }
    if(s[0] == 'x' && animal[0] == 1){
      if(animal[n - 1] == animal[1]){
	flag = true;
      }
    }
    //
    if(s[n - 1] == 'o' && animal[n - 1] == 0){
      if(animal[0] != animal[n - 2]){
	flag = false;
      }
    }
    if(s[n - 1] == 'o' && animal[n - 1] == 1){
      if(animal[0] != (animal[n - 2] + 1) % 2){
	flag = false;
      }
    }
    if(s[n - 1] == 'x' && animal[n - 1] == 0){
      if(animal[0] != (animal[n - 2] + 1) % 2){
	flag = false;
      }
    }
    if(s[n - 1] == 'x' && animal[n - 1] == 1){
      if(animal[0] != animal[n - 2]){
	flag = false;
      }
    }
    if(flag){
      break;
    }
  }

  if(flag){
    for(int i = 0; i < n; i++){
      if(animal[i] == 0){
	cout << "S";
      }
      else{
	cout << "W";
      }
    }
    cout << endl;
  }
  else{
    cout << -1 << endl;
  }
}
