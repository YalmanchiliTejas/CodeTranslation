#include <iostream>
#include <string>
using namespace std;

int n;

int main(){
	int max,m,n,money,H,y,tanri,hukuri,tesuu,okane,risi;
	double ritu;
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> money;
		cin >> y;
		cin >> n;
		max=0;
		for(int j=0;j<n;j++){
			risi=0;
			okane=money;
			cin >> H >> ritu >> tesuu;
			if(H==0){ //tanri
				for(int k=0;k<y;k++){
					risi+=okane*ritu;
					okane-=tesuu;
				}
				okane+=risi;
			} else { // hukuri
				for(int k=0;k<y;k++){
					risi=okane*ritu;
					okane+=risi;
					okane-=tesuu;
				}
			}
			if(max<=okane){
				max=okane;
			}
		}
		cout << max << endl;
	}

	return 0;
}