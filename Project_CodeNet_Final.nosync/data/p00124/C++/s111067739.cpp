#include <iostream>
#include <string.h>
using namespace std;

struct data{

	char name[21];
	int win;
	int lose;
	int draw;
	int score;

};

int main(){

	int teamamo;
	bool check = true;

	while (true){

		cin >> teamamo;

		if (teamamo == 0)
			break;

		data teamdata[10];
		

		for (int i = 0; i<teamamo; i++)
			cin >> teamdata[i].name >> teamdata[i].win >> teamdata[i].lose >> teamdata[i].draw;

		for (int i = 0; i<teamamo; i++)
			teamdata[i].score = teamdata[i].win * 3 + teamdata[i].draw;


		for (int j = 0; j < teamamo - 1; j++){
			for (int i = 0; i < teamamo - 1; i++){

				if (teamdata[i].score < teamdata[i + 1].score){

					data t = teamdata[i];
					teamdata[i] = teamdata[i + 1];
					teamdata[i + 1] = t;

				}

			}


		}

		if (check)
			check = false;
		else
			cout << endl;

		for (int i = 0; i<teamamo; i++)
			cout << teamdata[i].name << "," << teamdata[i].score << endl;

		


	}

	return 0;

}