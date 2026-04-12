#include <bits/stdc++.h>
using namespace std;

int main(){
  
int N, kazu;
  cin >> N;
int c[26][N];
  for(int i = 0;i < 26;i++){
  for(int j = 0;j < N;j++) c[i][j] = 0;
  }
  
string s;
  
  for(int i = 0;i < N;i++){
  cin >> s;
    for(int j = 0;j < s.size();j++) c[s.at(j) - '0' - 49][i]++;    
  }
  
  for(int i = 0;i < 26;i++){
  kazu = 51;
    for(int j = 0;j < N;j++){
    kazu = min(kazu, c[i][j]);
    }
    if(kazu > 0){
      while(kazu){    
      if(i == 0)cout << 'a';
      else if(i == 1)cout << 'b';  
        else if(i == 2)cout << 'c';
        else if(i == 3)cout << 'd';
        else if(i == 4)cout << 'e';
        else if(i == 5)cout << 'f';
        else if(i == 6)cout << 'g';
        else if(i == 7)cout << 'h';
        else if(i == 8)cout << 'i';
        else if(i == 9)cout << 'j';
        else if(i == 10)cout << 'k';
        else if(i == 11)cout << 'l';
        else if(i == 12)cout << 'm';
        else if(i == 13)cout << 'n';
        else if(i == 14)cout << 'o';
        else if(i == 15)cout << 'p';
        else if(i == 16)cout << 'q';
        else if(i == 17)cout << 'r';
        else if(i == 18)cout << 's';
        else if(i == 19)cout << 't';
        else if(i == 20)cout << 'u';
        else if(i == 21)cout << 'v';
        else if(i == 22)cout << 'w';
        else if(i == 23)cout << 'x';
        else if(i == 24)cout << 'y';
        else if(i == 25)cout << 'z';
        
        kazu--;
    }
  }
  }

  return 0;
  
}