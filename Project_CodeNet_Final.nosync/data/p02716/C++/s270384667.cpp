#include <iostream>
using namespace std;

long map[200000][2][3];
long a[200000];

bool possible[200000][2][3];

long saidai(int x, bool on, int drift){
  long y,z;
  long ret;
  bool pos;

  if(!on && drift == 0){
    ret = map[x-1][1][0];
    pos = possible[x-1][1][0];
  } else if(on && drift == 0){
    ret = map[x-1][0][0]+a[x];
    pos = possible[x-1][0][0];
  }
  else if(!on && drift > 0){
    y = map[x-1][1][drift];
    z = map[x-1][0][drift-1];
    if(possible[x-1][1][drift] && possible[x-1][0][drift-1]){
      ret = (y >= z)? y:z;
      //cout << ret << endl;
    } else if(possible[x-1][1][drift]) ret = y;
    else ret = z;
    pos = possible[x-1][1][drift] || possible[x-1][0][drift-1];
  }else{
    ret = map[x-1][0][drift]+a[x];
    pos = possible[x-1][0][drift];
  }
  map[x][(on)?1:0][drift] = ret;
  possible[x][(on)?1:0][drift] = pos;
  return ret;
}

int main(){
  int N;
  cin >> N;

  long x,y,ret;
  for(int i=0;i<N;i++) cin >> a[i];
  
  //for(int i=0;i<N;i++) map[0][i] = -1;
  //for(int i=0;i<N;i++) map[1][i] = -1;
  //for(int i=0;i<N;i++) map[2][i] = -1;
  map[0][0][1] = 0;
  map[0][1][0] = a[0];
  possible[0][0][0] = false;
  possible[0][0][1] = true;
  possible[0][0][2] = false;
  possible[0][1][0] = true;
  possible[0][1][1] = false;
  possible[0][1][2] = false;
   

  for(int i=1;i<N;i++) for(int j=0;j<2;j++) for(int k=0;k<3;k++){	
	saidai(i,(j==1)? true:false,k);
	//cout << i << " " << j << " " << k << " " << map[i][j][k] << " " << possible[i][j][k]<< endl;
      }  
  if(N % 2 == 0){
    x = map[N-1][0][0];
    y = map[N-1][1][1];
  }else{
    x = map[N-1][0][1];
    y = map[N-1][1][2];
  }
  ret = (x>=y)? x:y;
  cout << ret << endl;
}
