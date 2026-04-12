// 2011/09/08 Tazoe

#include <iostream>
#include <string>
using namespace std;

void North(int D[6])
{
	int tmp = D[0];
	D[0] = D[1];
	D[1] = D[5];
	D[5] = D[3];
	D[3] = tmp;
}

void East(int D[6])
{
	int tmp = D[0];
	D[0] = D[4];
	D[4] = D[5];
	D[5] = D[2];
	D[2] = tmp;
}

void West(int D[6])
{
	int tmp = D[0];
	D[0] = D[2];
	D[2] = D[5];
	D[5] = D[4];
	D[4] = tmp;
}

void South(int D[6])
{
	int tmp = D[0];
	D[0] = D[3];
	D[3] = D[5];
	D[5] = D[1];
	D[1] = tmp;
}

void Right(int D[6])
{
	int tmp = D[1];
	D[1] = D[2];
	D[2] = D[3];
	D[3] = D[4];
	D[4] = tmp;
}

void Left(int D[6])
{
	int tmp = D[1];
	D[1] = D[4];
	D[4] = D[3];
	D[3] = D[2];
	D[2] = tmp;
}

int main()
{
	while(true){
		int n;
		cin >> n;
		if(n==0)
			break;

		int D[6] = {1, 2, 3, 5, 4, 6};
		int sum = D[0];
		for(int i=0; i<n; i++){
			string str;
			cin >> str;

			if(str=="North")
				North(D);
			else if(str=="East")
				East(D);
			else if(str=="South")
				South(D);
			else if(str=="West")
				West(D);
			else if(str=="Right")
				Right(D);
			else if(str=="Left")
				Left(D);

			sum += D[0];
		}

		cout << sum << endl;
	}

	return 0;
}