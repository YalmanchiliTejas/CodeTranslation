#include <iostream>
using namespace std;
#define rep2(x,from,to) for(int x=(from);x<(to);++(x))
#define rep(x,to) rep2(x,0,to)
int main(){
	int am,pm;
	while(cin >> am >> pm) {
		if(am==0&&pm==0) break;
		int ret = am + pm;
		char shop = 'A';
		rep2(i,1,5) {
			cin >> am >> pm;
			if(ret < am + pm) {
				ret = am + pm;
				shop = 'A' + i;
			}
		}
		cout << shop << " " << ret << endl;
	}
	return 0;
}