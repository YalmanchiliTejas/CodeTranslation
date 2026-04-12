#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<functional>
using namespace std;

#define INF 1<<21
#define MOD 1000000007

int main(void) {
  int m;
  int A;
  int year;
  int n;
  int ri,tes;
  double per;
  int ans;
  cin >> m;
  for (int H = 0; H < m; H++) {
	cin >> A;
	cin >> year;
	cin >> n;
	int tmp = A;
	ans = 0;
	for (int i = 0; i < n; i++) {
	  cin >> ri >> per >> tes;
	  int risi = 0;
	  A = tmp;
	  int B;
	  if (ri == 0) {
		for (int j = 0; j < year; j++) {
		  B = A*per;
		  risi += B;
		  A -= tes;
		}
		ans = max(ans, A + risi);
	  }
	  else if (ri == 1) {
		for (int j = 0; j < year; j++) {
		  B = A*per;
		  risi = A + B - tes;
		  A = risi;
		}
		ans = max(ans, risi);
	  }
	}
	cout << ans << endl;
  }
}