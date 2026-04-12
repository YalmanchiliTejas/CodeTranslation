#include<iostream> 
using namespace std;

int main(){
	int n;
	cin >> n;

	char zoo_s[n];    

	cin >> zoo_s;

	char zoo[n + 1];
	int i = 0;

	while(1){
		switch(i){
			case 0:
				zoo[0] = zoo[1] = 'S';
				break;
			case 1:
				zoo[0] = 'S';
				zoo[1] = 'W';
				break;
			case 2:
				zoo[0] = 'W';
				zoo[1] = 'S';
				break;
			case 3:
				zoo[0] = zoo[1] = 'W';
				break;
		}

		for(int k = 1; k < n; ++k){
			if(zoo[k] == 'S'){
				if(zoo[k - 1] == 'S' && zoo_s[k] == 'o'){
					zoo[k + 1] = 'S';
				}else if(zoo[k - 1] == 'S' && zoo_s[k] == 'x'){
					zoo[k + 1] = 'W';
				}else if(zoo[k - 1] == 'W' && zoo_s[k] == 'o'){
					zoo[k + 1] = 'W';
				}else{
					zoo[k + 1] = 'S';
				}
			}else{
				if(zoo[k - 1] == 'S' && zoo_s[k] == 'o'){
					zoo[k + 1] = 'W';
				}else if(zoo[k - 1] == 'S' && zoo_s[k] == 'x'){
					zoo[k + 1] = 'S';
				}else if(zoo[k - 1] == 'W' && zoo_s[k] == 'o'){
					zoo[k + 1] = 'S';
				}else{
					zoo[k + 1] = 'W';
				}
			}
		}

		if(zoo[n] == zoo[0]){
			if(i == 0){
				if(zoo_s[0] == 'o'){
					if(zoo[n - 1] == 'S'){
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}else{
					if(zoo[n - 1] == 'W'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}
			}else if(i == 1){
				if(zoo_s[0] == 'o'){
					if(zoo[n - 1] == 'W'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}else{
					if(zoo[n - 1] == 'S'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}
			}else if(i == 2){
				if(zoo_s[0] == 'o'){
					if(zoo[n - 1] == 'W'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}else{
					if(zoo[n - 1] == 'S'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}
			}else if(i == 3){
				if(zoo_s[0] == 'o'){
					if(zoo[n - 1] == 'S'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}else{
					if(zoo[n - 1] == 'W'){ 
						for(int j = 0; j < n; ++j){ 
							cout << zoo[j];
						}
							cout << "\n";
						break;
					}else{
						++i;
					}
				}
			}
		}else{
			++i;
		}

		if(i >= 4){
			cout << -1 << "\n";
			break;
		}
	}
	
	return 0;
}