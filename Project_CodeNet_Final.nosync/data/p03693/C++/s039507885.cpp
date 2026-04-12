#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  int r,g,b; cin >>r >>g >>b;
  int check=r*100+g*10+b;
  cout <<(!(check%4) ? "YES":"NO") <<endl;
  return 0;
}
