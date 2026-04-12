#include<iostream>
#include<string>
using namespace std;
string team[10];
int point[10];
bool isfirst = true;
int main(){
  int n,temp,cur;
  string name;
  while(1){
    cin >> n;
    if(n == 0)return 0;
    if(!isfirst){
      cout << endl;
    }
    for(int i = 0;i < n;i++){
      cin >> team[i];
      cin >> temp;
      point[i] += temp*3;
      cin >> temp;
      cin >> temp;
      point[i] += temp;
    }
    for(int j = 0;j < n;j++){
      for(int i = cur = 0;i < n;i++){
	if(point[i] > point[cur]) cur = i;
      }
      cout << team[cur] << ',' << point[cur] << endl;
      point[cur] = -1;
    }
    for(int i = 0;i < 10;i++){
      point[i] = 0;
    }
    isfirst = false;
  }
  return 0;
}