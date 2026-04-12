#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#define MAX(a,b) ((a)<(b) ? (a) : (b))
#define MIN(a,b) ((a)>(b) ? (a) : (b))
#define ABS(a) ((a)>0 ? (a) : (a * -1))

using namespace std;
int main(){
	int n, ans;
	cin >> n;
	ans = n * 800 - (n / 15 * 200);

	cout << ans << endl;
}
