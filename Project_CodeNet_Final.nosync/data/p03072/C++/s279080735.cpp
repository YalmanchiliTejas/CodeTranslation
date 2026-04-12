#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int h,hm=0,i,ans=0;
	for(i=1;i<=n;i++){
		cin >> h;
		if(h>=hm){
			ans++;
			hm = h;
		}
	}
	cout << ans << endl;
	return 0;
}