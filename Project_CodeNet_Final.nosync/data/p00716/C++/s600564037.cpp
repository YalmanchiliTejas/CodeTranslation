#include <iostream>

#define loop(i) for(int lp = 0; (lp) < (i); (lp) ++)

using namespace std;

int main() {
  int m, _A, year, n;
  cin >> m;
  loop(m) {
    cin >> _A >> year >> n;

    
    int ans = 0;
    for(int i = 0; i < n; i ++) {
      int A = _A;
      int B = 0;
      int C = 0;
      int type, t;
      double r;
      cin >> type >> r >> t;
      
      loop(year) {
	if(type) {
	  B = A*r;
	  A = A+B-t;
       	}
	else {
	  B = A*r;
	  A = A-t;
	  C += B;	
	}
      }

      ans = (ans>(A+C))?ans:(A+C);
    }

    cout << ans << endl;
  }
  return 0;
}