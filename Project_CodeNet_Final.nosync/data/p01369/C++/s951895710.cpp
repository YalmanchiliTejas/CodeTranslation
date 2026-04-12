#include <iostream>
#include <string>
using namespace std;

int main(){
	string n;
	string qwert = "qwertasdfgzxcvb";
	string yuiop = "yuiophjklnm";

	while(1){
		cin >> n;
		if(n[0] == '#') break;

		int typ = 0;
		int count = 0;
		for(int i = 0; i < n.size(); i++){
			if(typ){
				for(int j = 0; j < qwert.size(); j++){
					if(n[i] == qwert[j]){
						typ = 0;
						count++;
						if(i == 0) count--;
					}
				}
			}else{
				for(int j = 0; j < yuiop.size(); j++){
					if(n[i] == yuiop[j]){
						typ = 1;
						count++;
						if(i == 0) count--;
					}
				}
			}
		}

		cout << count << endl;
	}


	return 0;
}