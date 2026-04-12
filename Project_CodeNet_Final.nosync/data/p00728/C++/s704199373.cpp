#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n, ma, mi, tmp, ans;
	while(cin >> n){
		if(n == 0) break;
		ma = 0;
		mi = 1001;
		ans = 0;
		for(int i = 0;i<n;i++){
			cin >> tmp;
			ans += tmp;
			mi = fmin(tmp,mi);
			ma = fmax(tmp,ma);
		}
		cout << int(ans - mi - ma)/(n-2) << endl;
	}
	return 0;
}
