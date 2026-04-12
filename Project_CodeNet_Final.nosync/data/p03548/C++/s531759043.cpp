#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

main(){
  int x,y,z;
  cin >> x >> y >> z;
  x=x-z;
  cout << x/(y+z) << endl;
}