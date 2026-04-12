
#include <iostream>
using namespace std;

int main()
{
	int number;
	int score, sum, max, min;
	
	while(true)
	{
		cin >> number;
		if(!number) return 0;
		sum = 0, max = 0, min = 1000;
		for(int i = 0; i < number; ++i)
		{
			cin >> score;
			sum += score;
			if(score > max) max = score;
			if(score < min) min = score;
		}
		cout << (sum - max - min) / (number - 2) << endl;
	}
}