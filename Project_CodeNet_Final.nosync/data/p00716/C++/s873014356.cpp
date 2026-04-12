#include <iostream>
#include <algorithm>
using namespace std;

bool SortComp(long long int num1, long long int num2) { return num1 > num2 ? true : false; }

long long int FindRes(int check, long double rate, long long int charge, int year, long long int fund)
{
	long long int sum= 0;
	if(check == 0)
	{
		for(int i= 0; i < year; i++)
		{
			sum+= fund*rate;
			fund-= charge;
		}
		sum+= (long long int)fund;
	}
	else
	{
		sum= fund;
		for(int i= 0; i < year; i++)
			sum+= (long double)(sum*rate)-charge;
	}

	return sum;
}

int main(void)
{
	int num;
	cin>>num;
	for(int i= 0; i < num; i++)
	{
		long long int fund;
		cin>>fund;

		int year, operations;
		cin>>year>>operations;

		long long int sum[100]= {};
		for(int j= 0; j < operations; j++)
		{
			int check;
			long double rate;
			long long int charge;
			cin>>check>>rate>>charge;

			sum[j]= FindRes(check, rate, charge, year, fund);
		}

		sort(sum, sum+operations, SortComp);
		cout<<sum[0]<<endl;
	}

	return 0;
}