#include <iostream>
#include <string>
using namespace std;

int main(){
	int a,b,ab,x,y;
	cin >> a >> b >> ab >> x >> y;
	int yen = 0;

	if(a+b <= ab*2){
		yen = x * a + y * b;
	}else{
		if(x < y){
			yen += x * ab * 2;
			if(b > ab * 2){
				yen += (y - x) * ab * 2;
			}else{
				yen += (y - x) * b;
			}
		}else{
			yen += y * ab * 2;
			if(a > ab * 2){
				yen += (x - y) * ab * 2;
			}else{
				yen += (x - y) * a;
			}
		}
	}
	
	cout << yen << endl;

	return 0;
}