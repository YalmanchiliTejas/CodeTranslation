#include <iostream>
#include <string>
using namespace std;
int main(){
	while (1) {
		int n;
		cin>>n;
		if(n == 0)break;
		int dice[3] = {1,2,3};
		int before[3] = {1,2,3};
		int sum = 1;
		for (int i = 0; i < n; i++) {
			string verb;
			cin>>verb;
			if (verb == "North") {
				dice[0] = before[1];
				dice[1] = 7-before[0];
			} else if (verb == "East") {
				dice[0] = 7-before[2];
				dice[2] = before[0];
			} else if (verb == "West") {
				dice[0] = before[2];
				dice[2] = 7-before[0];
			} else if (verb == "South") {
				dice[0] = 7-before[1];
				dice[1] = before[0];
			} else if (verb == "Right") {
				dice[1] = before[2];
				dice[2] = 7-before[1];
			} else if (verb == "Left") {
				dice[1] = 7-before[2];
				dice[2] = before[1];
			}
			for (int j = 0; j < 3; j++) {
				before[j] = dice[j];
			}
			sum += dice[0];
		}
		cout<<sum<<endl;
	}
	return 0;
}