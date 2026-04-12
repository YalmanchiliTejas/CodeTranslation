#include<algorithm>
#include<cstdio>
#include<functional>
#include<iostream>
#include<cfloat>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<time.h>
#include<vector>
using namespace std;
const int oo = 0x3f3f3f3f;
int a , b , c , x , y;
int main(){
	cin >> a >> b >> c >> x >> y;
	int ans = 2 * oo;
	for(int i = 0 ; i <= max(2 * x , 2 * y) ; i += 2){
		int la = max(0 , x - i / 2);
		int lb = max(0 , y - i / 2);
		ans = min(ans , la * a + lb * b + i * c);
	} 
	cout << ans << endl;
	system("pause");
	return 0;
}