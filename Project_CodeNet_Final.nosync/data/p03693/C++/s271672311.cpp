#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int a, b, c;
  cin >> a >> b >> c;
  int red = a*100;
  int green = b*10;
  int blue = c;
  int num = red + green + blue;
  if(num % 4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
	
}