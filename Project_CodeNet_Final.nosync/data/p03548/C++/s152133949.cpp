#include <iostream>

typedef long long ll;

#define FOR(i,a,b) for(ll i = (a);i < (b);++i)
#define REP(i,n) FOR(i,0,n)

#define debug(x) cout << #x << "=" << x << endl;

using namespace std;

int main(void){

  int x,y,z;
  cin >> x >> y >> z;

  int width = z+y;

  int ideal = x / width;
  
  if(ideal * width > x - z){
    ideal--;
  }

  cout << ideal << endl;

    
  return 0;
}
