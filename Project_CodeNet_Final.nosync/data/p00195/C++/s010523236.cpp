#include <iostream>
using namespace std;

int main(){
	int a[5],b[5];
	while(cin >> a[0] >> b[0] && (a[0]||b[0])){
		int best = 0;
		for(int i = 1 ; i <= 4 ; i++){
			cin >> a[i] >> b[i];
			if( a[i]+b[i] >= a[best] + b[best] ){
				best = i;
			}
		}
		cout << (char)('A'+best) << " "<< a[best]+b[best] << endl;
		
	}
}