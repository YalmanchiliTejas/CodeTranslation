#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d, si;
  string str;

  while(1){
    int map[20][20] = {}, h = 1, w = 1, counta; 
    cin>>str;
    if(str == "#") break;
    cin>>a>>b>>c>>d;
    si = str.size();
    for(int i = 0; i < si; i++){
      if(h==a&&w==b) str[i] = '1';
      if(str[i] == 'b'){map[h][w] = 1;w++;}
      else if(str[i] == '/'){h++;w=1;}
      else w+= str[i]-'0';
    }map[c][d] = 1;
    for(int i = 1; i <= h; i++){
      counta = 0;
      for(int j = 1; j < w; j++){
	counta++;
	if(map[i][j] == 1){
	  if(counta-1)cout<<counta-1;
	  cout<<'b';
	  counta = 0;
	}
      }
      if(counta)cout<<counta;
      if(i!=h)cout<<'/';
    }cout<<endl;
  }

  return 0;
}

