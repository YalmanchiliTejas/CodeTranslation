#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int H,W;
  cin >> H >> W;
  char a[H][W];
  int N[H],M[W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a[i][j];
      N[i]=0;
      M[j]=0;
    }
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a[i][j]=='#'){
	N[i]+=1;
	M[j]+=1;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(N[i]!=0){
      for(int j=0;j<W;j++){
	if(M[j]!=0) cout << a[i][j];
      }
      cout << endl;
    }
  }
}
