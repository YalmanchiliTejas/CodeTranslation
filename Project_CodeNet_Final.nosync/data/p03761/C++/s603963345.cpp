#include <bits/stdc++.h>
#define FOR(I,X,Y) for(int (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(int (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define INF 1000000007
#define LINF 1000000000000000007
typedef long long ll;
using namespace std;

int a[100];
int Min[100];

int main(){
  int n;
  cin >> n;
  FOR(i,0,100)Min[i] = INF;
  string S;
  FOR(i,0,n){
    cin >> S;
    FOR(i,0,100)a[i] = 0;
    FOR(i,0,S.size())a[S[i] - 'a']++;
    FOR(i,0,100)Min[i] = min(a[i],Min[i]);
  }
  for(char c = 'a';c <= 'z';c++){
    FOR(i,0,Min[c - 'a'])cout << c;
  }
  cout << endl;
}
