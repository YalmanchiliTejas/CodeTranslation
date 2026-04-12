#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n) ; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
  int n,m,l;
  cin >> n >> m >> l;
  if( ((10*m+l)%4) == 0) {
    printf("YES");
  }
  else{
    printf("NO");
  }
    return 0;
}
