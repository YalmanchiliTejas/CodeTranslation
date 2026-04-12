#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct team{
	string name;
	int point;
};

team teams[50];

int main(){
	
	int n;
	
	cin >> n;
	
	while(true){
		if(n == 0){
			break;
		}
		
		int a, b, c;
		for(int i = 0; i < n; i++){
			cin >> teams[i].name;
			cin >> a >> b >> c;
			teams[i].point = a * 3 + c;
		}
		
		for(int i = 0; i < n; i++){
			for(int j = n - 1; j > 0; j--){
				if(teams[j - 1].point < teams[j].point){
					swap(teams[j - 1], teams[j]);
				}
			}
		}
		
		for(int i = 0; i < n; i++){
			cout << teams[i].name << "," << teams[i].point << endl;
		}
		cin >> n;
		if(n != 0){
			cout << endl;
		}
	}
	
	return 0;
}