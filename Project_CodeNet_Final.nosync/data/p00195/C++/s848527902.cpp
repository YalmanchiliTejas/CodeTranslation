#include <iostream>
#include <string>
using namespace std;

int main(){
	int sum[5], n, m, ans;
	bool flag = false;

	while(1){
		for(int i=0 ; i<5 ; i++){
			sum[i] = 0;

			cin >> n >> m;
			if( n==0 && m==0 ){
				flag = true;
				break;
			}
			sum[i] += n+m;
		}
		if( flag ) break;
		ans = 0;
		for(int i=1 ; i<5 ; i++){
			if( sum[ans] < sum[i]) ans = i;
		}
		char s = ans + 'A';
		cout << s << " " << sum[ans] << endl;
	}

	return 0;
}