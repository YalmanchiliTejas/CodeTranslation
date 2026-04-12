#include <iostream>
#include <string>
using namespace std;

int a[300], b[300];

void re(){
	for(int i = 0;i<300;i++){
		a[i] = 100;
	}
}


void res(){
	for (int i = 0; i<300; i++) {
		b[i] = 0;
	}
}
int main(){
	int k;
	string input, ans;
	while(cin >> k){
		re();
		for(int i = 0;i<k;i++){
			cin >> input;
			res();
			for(int j = 0;j<input.size();j++){
				int v = input[j];
				b[v]++;
			}
			for (int z = 0; z<300; z++) {
				if (a[z] > b[z])a[z] = b[z];
			}
		}
		ans = "";
		for (int i = 97; i<300; i++) {
			if(a[i] != 0){
				for(int j = 0;j<a[i];j++){
					ans += i;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}