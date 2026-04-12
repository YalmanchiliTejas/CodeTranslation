#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
string k;
int d;
long long bio[10005][105][2];
int br = 0;
long long modz(long long x, long long y)
{
	if(x+y >= MOD)
	{
		return x+y-MOD;
	}
	return x+y;
}
long long r(int poz, int o, bool f)
{
	if(poz == k.size() && o == 0)
	{
		return 1;
	}
	if(poz == k.size())
	{
		return 0;
	}
	if(bio[poz][o][f] != -1)
	{
		return bio[poz][o][f];
	}
	bio[poz][o][f] = 0;
	int z;
	if(f == 0)
	{
		z = k[poz] - '0';
	}
	else
	{
		z = 9;
	}
	for(int i = 0; i <= z; i++)
	{
		int no = (o+i) % d;
		if(f == 1 || i < z)
		{
			bio[poz][o][f] = modz(bio[poz][o][f], r(poz+1, no, 1));
		}
		else
		{
			bio[poz][o][f] = modz(bio[poz][o][f], r(poz+1, no, 0));
		}
	}
	return bio[poz][o][f];
}
int main()
{
    cin >> k >> d;
    for(int i = 0; i < k.size(); i++)
    {
    	for(int j = 0; j < d; j++)
    	{
    		bio[i][j][0] = -1;
			bio[i][j][1] = -1; 
		}
	}
	cout << (r(0, 0, 0) - 1 + MOD) % MOD << endl;
}

