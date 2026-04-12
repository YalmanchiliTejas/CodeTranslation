#include <iostream>
#include <string>

using namespace std;

int main(){
	int o,n,d[6],e[6];
	string r;

	while(1){
		cin >> n;
		if(n != 0){

			o = 1;
			for(int i = 0; i < 6; i++){
				d[i] = e[i] = i+1;
			}

			for(int i = 0; i < n; i++){
				cin >> r;

				switch(r.at(0)){
					case 'N':
						e[0] = d[1];
						e[1] = d[5];
						e[5] = d[4];
						e[4] = d[0];
						break;
					case 'E':
						e[0] = d[3];
						e[3] = d[5];
						e[5] = d[2];
						e[2] = d[0];
						break;
					case 'W':
						e[0] = d[2];
						e[2] = d[5];
						e[5] = d[3];
						e[3] = d[0];
						break;
					case 'S':
						e[0] = d[4];
						e[4] = d[5];
						e[5] = d[1];
						e[1] = d[0];
						break;
					case 'R':
						e[1] = d[2];
						e[2] = d[4];
						e[4] = d[3];
						e[3] = d[1];
						break;
					case 'L':
						e[1] = d[3];
						e[3] = d[4];
						e[4] = d[2];
						e[2] = d[1];
						break;
				}

				for(int j = 0; j < 6; j++){
					d[j] = e[j];
				}

				o += d[0];
			}

			cout << o << endl;
		}else{
			break;
		}
	}

	return 0;
}