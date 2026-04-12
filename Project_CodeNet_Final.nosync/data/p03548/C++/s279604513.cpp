#include <iostream>
using namespace std;

int main() {
	
	int X, Y, Z;
	cin>>X>>Y>>Z;
	
	int ans = 0;
	int sum = 0;
	bool f = false;
	while(true){
		if(f){
			if(sum + Y > X) break;
			ans++;
			sum += Y;
			f = false;
		}else{
			if(sum + Z > X) {
				if(ans > 0)ans--;
				break;
			}
			sum += Z;
			f = true;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}