#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
typedef long long ll;


int main(){
  int n;
  cin >> n;
  int x = 0,y = 0;
  rep1(i,n){
    x += 800;
    if(i%15==0)y += 200;
  }
  cout << x-y << endl;
}
