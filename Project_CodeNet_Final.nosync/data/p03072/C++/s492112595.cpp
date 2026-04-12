#include<iostream>

using namespace std;

int main()
{ int n,i,j,counter;
int tinggi [100];
	cin >> n;
	counter = 0;
	for(i=0;i<n;i++)
	{
		cin >> tinggi[i];
		for(j=0;j<=i;j++)
		{
			if(tinggi[i] - tinggi[j] >= 0)
			{
				
			}
			else break;
			if(i==j)
			{
				counter++;
			}
		}
	}
	cout << counter << endl;
}