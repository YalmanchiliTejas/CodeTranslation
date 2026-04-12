#include <iostream>
#include <string>

using namespace std;

int n;
string str;
typedef unsigned long long ull;

int main() {
	while(cin >> n, n)
	{
		char dice[7] = {0, 1, 2, 3, 4, 5, 6};
		ull sum = 1;
		for(int i=0; i<n; i++)
		{
			char t;
			cin >> str;
			if(!str.compare("North"))
			{
				t = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = t;
			}

			else if(!str.compare("East"))
			{
				t = dice[4];
				dice[4] = dice[6];
				dice[6] = dice[3];
				dice[3] = dice[1];
				dice[1] = t;
			}

			else if(!str.compare("West"))
			{
				t = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = t;
			}

			else if(!str.compare("South"))
			{
				t = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = t;
			}

			else if(!str.compare("Right"))
			{
				t = dice[2];
				dice[2] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[4];
				dice[4] = t;
			}

			else if(!str.compare("Left"))
			{
				t = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[3];
				dice[3] = t;
			}

			sum += (ull)dice[1];
		}

		printf("%llu\n", sum);
	}
}