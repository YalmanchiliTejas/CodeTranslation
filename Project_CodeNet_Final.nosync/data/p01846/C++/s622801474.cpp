#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int m[9][9];
  while(s != "#"){
    int a = 0;
    int b = 0;
    int p = 0;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '/'){
	b = p;
	p = 0;
	a++;
      }else if(s[i] == 'b'){
	m[a][p] = 1;
	p++;
      }else{
	for(int j = 0; j < s[i]-'0'; j++){
	  m[a][p+j] = 0;
	}
	p += s[i] - '0';
      }
    }
    a++;
    int c,d,e,f;
    cin >> c >> d >> e >> f;
    m[c-1][d-1] = 0;
    m[e-1][f-1] = 1;
    for(int i = 0; i < a; i++){
      int g = 0;
      for(int j = 0; j < b; j++){
	if(m[i][j] == 1){
	  if(g == 0){
	    cout << 'b';
	  }
	  else{
	  cout << g << 'b';
	    g = 0;
	  }
	}
	else{
	  g++;
	  }
      }
      if(g != 0) cout << g;
      if(i != a-1)cout << "/";
      }
    cout << endl;
    cin >> s;
  }
  return 0;
}

