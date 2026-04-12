#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  int a=100*r+10*g+b;
  if(a%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;

}
