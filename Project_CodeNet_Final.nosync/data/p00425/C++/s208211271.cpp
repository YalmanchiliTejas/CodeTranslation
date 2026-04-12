#include <iostream>
#include <string>
using namespace std;

string way[6];
string instr;



int main(void)
{
	int N = 1;

	way[0] += "North";
	way[1] += "East";
	way[2] += "West";
	way[3] += "South";
	way[4] += "Right";
	way[5] += "Left";


	while(cin >> N, N > 0){
int dice[] = {1,3,6,4,2,5};
	int sum = 1;

	int t;
	for(int i = 0; i < N; i++){
		cin >> instr;

		if(instr == way[0]){
			t = dice[0];
			dice[0] = dice[4];	dice[4] = dice[2];	dice[2] = dice[5];	dice[5] = t;
		} 
		else if(instr == way[1]){
			t = dice[0];
			dice[0] = dice[3];	dice[3] = dice[2];	dice[2] = dice[1];	dice[1] = t;
		}
		else if(instr == way[2]){
			t = dice[0];
			dice[0] = dice[1];	dice[1] = dice[2];	dice[2] = dice[3];	dice[3] = t;
		}
		else if(instr == way[3]){
			t = dice[0];
			dice[0] = dice[5];	dice[5] = dice[2];	dice[2] = dice[4];	dice[4] = t;
		}


		else if(instr == way[5]){
			t = dice[5];
			dice[5] = dice[1];	dice[1] = dice[4];	dice[4] = dice[3];	dice[3] = t;
		}
		else if(instr == way[4]){
			t = dice[5];
			dice[5] = dice[3];	dice[3] = dice[4];	dice[4] = dice[1];	dice[1] = t;
		}

		sum += dice[0];


	}


		cout << sum << endl;
}
	return 0;
}