#include <iostream>
#include <string>
using namespace std;
int main(){
  string S;
  int a, b, c, d;
  while(cin >> S, S != "#"){
    cin >> a >> b >> c >> d;
    int B[9][9];
    for(int i = 0; i < 9; ++i) fill(B[i],B[i]+9,0);
    int x = 0, y = 0;
    for(int i = 0; i < (int)S.length(); ++i){
      char l = S[i];
      if(S[i] == 'b'){
	B[x][y] = 1;
	++y;
      }else if(S[i] == '/'){
	++x;
	y = 0;
      }else{
	y += l - '0';
      }
    }
    B[a-1][b-1] = 0;
    B[c-1][d-1] = 1;
    int t = 0;
    for(int i = 0; i <= x; ++i){
      for(int j = 0; j < y; ++j){
	if(B[i][j]){
	  if(t){
	    cout << t;
	    t = 0;
	  }
	  cout << "b";
	}else{
	  ++t;
	}
      }
      if(t){
	cout << t;
	t = 0;
      }
      if(i < x)
	cout << "/";
    }
    cout << endl;
  }
  return 0;
}