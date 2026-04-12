#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char out[10000];
	int count = 0, n;
	cin >> n;
	string block[n];
	for(int i = 0; i < 10000; i++){
		string order;
		cin >> order;
		if(order == "quit"){
			break;
		}
		else if(order == "push"){
			string color;
			int p;
			cin >> p >> color;
			block[p-1] = block[p-1] + color;
		}
		else if(order == "pop"){
			int p;
			cin >> p;
			out[count] = block[p-1][block[p-1].size()-1];
			block[p-1] = block[p-1].substr(0, block[p-1].size()-1);
			count++;
		}
		else{
			int p, q;
			char b;
			cin >> p >> q;
			b = block[p-1][block[p-1].size()-1];
			block[p-1] = block[p-1].substr(0, block[p-1].size()-1);
			block[q-1] = block[q-1]+b;
		}
	}
	for(int i = 0; i < count; i++){
		cout << out[i] << endl;
	}
}