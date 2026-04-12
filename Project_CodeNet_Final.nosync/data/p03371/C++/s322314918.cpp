#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define r(i,n) for(int i=0; i<n; i++)
typedef long long ll;
using namespace std;

int main(void){
	long a, b, c, x, y;
	long sum=0;

	cin >> a >> b >> c >> x >> y;
	if(a+b>2*c){
		sum+= min(x,y)*2*c;
		if(x<y){
			sum+=(y-x)*b;
		}else{
			sum+=(x-y)*a;
		}

		if(c*max(x,y)*2<sum){
			cout << c*max(x,y)*2 << endl;
		}else{
			cout << sum << endl;
		}
		
	}else{
		cout << a*x+b*y << endl;
	}
	return 0;
}