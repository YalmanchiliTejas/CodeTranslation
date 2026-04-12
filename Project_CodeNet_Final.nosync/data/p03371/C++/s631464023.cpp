#include <iostream>
#include <algorithm>
using namespace std ;

int main(){
	int a, b, c, x, y, cost = 0;
	cin >> a >> b >> c >> x >> y;
	if((a+b)/2 < c)	cost += a*x + b*y;
	else {
		if(x<y) {
			int cost_, cost_min = 1000000000;
			for(int i = 0; i <= y - x; i++) {
				cost_ = b*i + 2*c*(y-x-i);
				if(cost_min > cost_)	cost_min = cost_;
			}
			cost += c*2*x + cost_min;
		} else {
			int cost_, cost_min = 1000000000;
			for(int i = 0; i <= x-y; i++) {
				cost_ = a*i + 2*c*(x-y-i);
				if(cost_min > cost_)	cost_min = cost_;
			}
			cost += c*2*y + cost_min;
		}
	}
	cout << cost << "\n";
}