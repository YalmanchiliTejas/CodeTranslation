#include <iostream>
using namespace std;
int main(){
	int a, b=0, t=0, n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a;
		if (a>=b){
			t++;
			b=a;
		}
	}cout << t << endl;
	return 0;
}