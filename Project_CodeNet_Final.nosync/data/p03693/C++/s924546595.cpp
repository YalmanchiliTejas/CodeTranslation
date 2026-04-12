#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define reps(i,s,n) for(int (i) = (s); (i) < (n); ++(i))
#define rep(i,n) reps(i,0,n)
using ll = long long;
     
int main(){
	int r,g,b;
	cin >> r >> g >> b;
	int s = 100*r + 10 *g + b;
	if(s % 4==0)cout << "YES" << endl;
	else cout << "NO" <<endl;
	return 0;
}
