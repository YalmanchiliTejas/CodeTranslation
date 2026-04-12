#include <iostream>

using namespace std;

int main(){
  
  int H,W,sharp = 0;
  cin >> H >> W;
  char s;
  
  for (int i=0;i<H;i++){
   for(int j=0;j<W;j++){
	cin >> s;
    sharp += (int)(s=='#');
   }
  }
  
  cout << ((sharp == H + W - 1) ? "Possible" : "Impossible") << endl;
  
}