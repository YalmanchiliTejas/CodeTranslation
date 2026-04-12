#include <bits/stdc++.h>
#define FOR(I,X,Y) for(int (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(int (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define INF 1000000007
#define LINF 1000000000000000007
typedef long long ll;
using namespace std;

int main(){
  string S;
  cin >> S;
  FOR(i,0,S.size()-1){
    if(S.substr(i,2) == "AC"){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
