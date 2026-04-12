#include <iostream>
using namespace std;

int main(){
	int m,n,money,y,A,tmp,sum,r,mx;
	double rate;
	cin >> m;
	
	while(m--){
		cin >> money >> y >> n;
		mx = 0;
		for(int i=0;i<n;i++){
			cin >> r >> rate >> A;
			tmp = money;
			sum = 0;
			if(!r){
				for(int i=0;i<y;i++){
					sum += tmp*rate ;
					tmp -= A;
				}
				mx = max(mx,sum+tmp);
			}else{
				for(int i=0;i<y;i++){
					tmp += tmp*rate ;
					tmp -= A;
				}
				mx = max(mx,tmp);
			}
		}
		cout << mx << endl;
	}
}