#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int counter = 0;
  X -= Z;
  while(X >= Y + Z){
    X -= Y + Z;
    counter++;
  }
  cout << counter << endl;
}
