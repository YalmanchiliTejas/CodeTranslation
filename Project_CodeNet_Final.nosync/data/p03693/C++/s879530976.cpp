#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
int a,b,c; cin >> a >> b >> c;
  b = 10*b+c;
  if( b%4 == 0){ cout <<"YES" << endl;}
  else{ cout << "NO" << endl;}
  
  return 0;
}
      
