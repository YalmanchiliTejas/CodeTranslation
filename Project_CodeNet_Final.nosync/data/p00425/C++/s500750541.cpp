#include <iostream>
#include <string>

int w[] = {1,2,6,5,3,4};
//0上、1手前、2下、3奥、4右、5左

using namespace std;

void Shift(int a,int b,int c,int d)//左へつめる
{
	int e = w[a];
	w[a] = w[b];
	w[b] = w[c];
	w[c] = w[d];
	w[d] = e;
}

void Set()
{
	w[0] = 1;
	w[1] = 2;
	w[2] =6;
	w[3] = 5;
	w[4] = 3;
	w[5] = 4;
}

int main(void)
{
	int n;
	string s;
	int sum=0;
	while(1)
	{
		cin >> n;
		if(n==0)
			return 0;
		sum = 0;
		Set();
		for(int i=0;i<n;++i)
		{
			cin >> s;
			if(s[0] == 'N')
			{
				Shift(0,1,2,3);
			}
			if(s[0] == 'E')
			{
				Shift(0,5,2,4);
			}
			if(s[0] == 'W')
			{
				Shift(0,4,2,5);
			}
			if(s[0] == 'S')
			{
				Shift(0,3,2,1);
			}
			if(s[0] == 'R')
			{
				Shift(1,4,3,5);
			}
			if(s[0] == 'L')//0上、1手前、2下、3奥、4右、5左
			{
				Shift(1,5,3,4);
			}
			sum+=w[0];
		}
		cout << sum+1 << endl;
	}
	return 0;
}