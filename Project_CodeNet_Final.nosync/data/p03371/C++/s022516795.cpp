#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;

int main(){
  ll A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
  
 ll min_sum = 1e11; 
  
  for(ll z = 0; z <= 2 * max( X,Y); z += 2){
    ll sum = 0;
    ll x = X - z / 2; if( x < 0){ x = 0;}
    ll y = Y - z / 2; if( y < 0){ y = 0;}
    sum = x * A + y * B + z * C ;
    
    min_sum = min( min_sum,sum);}
  
  cout << min_sum << endl; return 0;}
    