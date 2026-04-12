#include <iostream>
#include <string>
using namespace std;


int main(void){
	int n;
	cin >> n;
	while(n){
		int dice[7] = {0,1,2,3,4,5,6};
		int pattern[6][4] = {{1,2,6,5},{1,4,6,3},{1,3,6,4},{1,5,6,2},{2,3,5,4},{2,4,5,3}};
		int i ,p ,sum = 1;
		string dire;
		for(int i = 0; i < n; i++){
			cin >> dire;
			if(dire == "North") p = 0;
			else if(dire == "East") p = 1;
			else if(dire == "West") p = 2;
			else if(dire == "South") p = 3;
			else if(dire == "Right") p = 4;
			else p = 5;

			dice[0] = dice[pattern[p][0]];
			for(int j = 0; j < 3; j++)
				dice[pattern[p][j]] = dice[pattern[p][j + 1]];
			dice[pattern[p][3]] = dice[0];
			sum += dice[1];
		}	
		cout << sum;
		cout << endl;
		cin >> n;
	}	
}