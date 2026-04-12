#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	int n;
	while (cin >> n && n != 0){
		int t = 1, s = 2, e = 3;
		int total = 1;
		for (int i = 0; i < n; i++){
			string word;
			cin >> word;
			if (word == "North"){
				swap(t, s);
				s = 7 - s;
			}
			if (word == "East"){
				swap(t, e);
				t = 7 - t;
			}
			if (word == "West"){
				swap(t, e);
				e = 7 - e;
			}
			if (word == "South"){
				swap(t, s);
				t = 7 - t;
			}
			if (word == "Right"){
				swap(s, e);
				e = 7 - e;
			}
			if (word == "Left"){
				swap(s, e);
				s = 7 - s;
			}
			total += t;
		}
		cout << total << endl;
	}
}


