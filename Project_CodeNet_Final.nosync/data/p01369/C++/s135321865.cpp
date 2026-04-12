#include <bits/stdc++.h>

using namespace std;

int main(void) {
  char str[33];

  char l[15] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b'};

  char r[11] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
  
  while(1){
    cin >> str; if(str[0] == '#') break;
    
    int counter = 0;
    int flag = 0;
    for(int i = 0; str[i] != '\0'; i++){
      
      for(int j = 0; j < 15; j++){
	if(str[i] == l[j]){
	  if(flag == 2) counter++;
	  flag = 1;
	  break;
	}
      }

      for(int j = 0; j < 11; j++){
	if(str[i] == r[j]){
	  if(flag == 1) counter++;
	  flag = 2;
	  break;
	}
      }
    
    }

    cout << counter << endl;

  }

  return 0;

}