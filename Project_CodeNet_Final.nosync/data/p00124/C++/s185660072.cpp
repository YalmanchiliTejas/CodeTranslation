#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef struct{
  string name;
  int sum;
}TEAM;

int main(){
  int rev = 0;
  int num;
  while(cin >> num && num){
    if(rev) cout << endl;
    rev++;
    int win, lose, draw;
    TEAM team[num];
    for(int i = 0; i < num; i++){
      cin >> team[i].name >> win >> lose >> draw;
      team[i].sum = win*3 + draw;
    }
    for(int i = 0; i < num-1; i++){
      for(int j = 0; j < num-i-1; j++){
	if(team[j].sum < team[j+1].sum){
	  TEAM tmp = team[j];
	  team[j] = team[j+1];
	  team[j+1] = tmp;
	}
      }
    }
    for(int i = 0; i < num; i++){
      cout << team[i].name <<"," << team[i].sum<<endl;
    }
  }
  return 0;
}