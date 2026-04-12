#include <iostream>
#include <string>
using namespace std;
int main()
{

	int n, sum, dice[6];
	string sup;

	cin >> n;

	while (n != 0){

		sum = 1;
		for (int i = 0; i < 6; i++)	dice[i] = i + 1;


		for (int i = 0; i < n; i++){
			cin >> sup;
			switch (sup[0])
			{
				int temp;
			case 'N':
				temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;
				sum += dice[0];
				break;
			case 'E':
				temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
				sum += dice[0];
				break;
			case 'W':
				temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;
				sum += dice[0];
				break;
			case 'S':
				temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;
				sum += dice[0];
				break;
			case 'R':
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = temp;
				sum += dice[0];
				break;
			case 'L':
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[2];
				dice[2] = temp;
				sum += dice[0];
				break;
			default:
				break;
			}
		}

		cout << sum << endl;

		cin >> n;

	}

}