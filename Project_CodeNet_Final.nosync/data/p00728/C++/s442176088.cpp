#include <iostream>
using namespace std;

int main()
{
	int number;
	int score[100];
	int sum, max, min;
	
	while(true)
	{
		cin >> number;
		if(!number) return 0;
		sum = 0, max = 0, min = 1000;
		for(int i = 0; i < number; ++i)
		{
			cin >> score[i];
			sum += score[i];
			if(score[i] > max) max = score[i];
			if(score[i] < min) min = score[i];
		}
		cout << (sum - max - min) / (number - 2) << endl;
	}
}