#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
  int n, m, i, j;

  while(true){
    cin >> n;
    int top = 1, bottom = 6,flont = 2, back = 5, right = 3, left = 4, temp = 0, score = 1;
    if(!n){ break; }
    for(i = 0; i < n; i++){
      string s;
      cin >> s;
      if(s=="North"){
        temp = top;
        top = flont;
        flont = bottom;
        bottom = back;
        back = temp;
      }
      else if(s == "South"){
        temp = top;
        top = back;
        back = bottom;
        bottom = flont;
        flont = temp;
      }
      else if(s == "East"){
	temp = top;
	top = left;
	left = bottom;
	bottom = right;
	right = temp;
      }
      else if(s == "West"){
	temp = top;
	top = right;
	right = bottom;
	bottom = left;
	left = temp;
      }
      else if(s == "Left"){
        temp = flont;
	flont = left;
	left = back;
	back = right;
	right = temp;
      }
      else if (s == "Right"){
	temp = flont;
	flont = right;
	right = back;
	back = left;
	left = temp;
      }
      score += top;
    }
    printf("%d\n", score);
  }
  return 0;
}