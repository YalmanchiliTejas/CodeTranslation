#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	int now=0, ans=0;
	for(int i=0; i<N; ++i){
	    int h; cin >> h;
	    if(now<=h){
	        ++ans;
	        now=h;
	    }
	}
	cout << ans << endl;
	return 0;
}
