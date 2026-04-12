#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <vector>
#include <tuple>
using namespace std;
//#define FILENAME "./F/in/b04"
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

#define MOD 1000000007

int n;
vector<int> a;
vector<int> x;

int main(int argc, char *argv[]) {

#ifdef FILENAME
  ifstream file(FILENAME);
  cin.rdbuf(file.rdbuf());
#endif

  cin >> n;
  a.resize(n);

  rep(i,n) {
    cin >> a[i];

    if(x.size()==0) { x.push_back(a[i]); continue; }

    if(a[i] <= x[0]) x.insert(x.begin(),a[i]);
    else if(a[i] > x[x.size()-1]) x[x.size()-1] = a[i];
    else {
      int l = 0; int r = x.size()-1; int k = 0;
      while(r-l>1) { // x[l] < a[i] <= x[r]
	k = (l+r)/2;
	if(x[k] < a[i]) l = k;
	else r = k;
      }
      x[l] = a[i];
    }
  }
  
  cout << x.size() << endl;
  
  return 0;
}
