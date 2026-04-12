#include <bits/stdc++.h>
#define MOD ((int)(1e9+7))

using namespace std;

string s;
int d;
int mem[10004][105][2];

int go(int ind,int r,int l)
{
	//cout << ind << " " << r << " " <<l << endl;
	if(ind>=s.size()) return r==0;
	if(mem[ind][r][l]!=-1) return mem[ind][r][l];
	mem[ind][r][l]=0;
	for(int i='0';i<=(l?'9':s[ind]);i++)
	{
		mem[ind][r][l]+=go(ind+1,(r+(i-'0'))%d,(i<s[ind])|l);
		mem[ind][r][l]%=MOD;
	}
	return mem[ind][r][l];
}

int main()
{
	cin >> s >> d;
	memset(mem,-1,sizeof mem);
	cout << (go(0,0,0)+MOD-1)%MOD << endl;
}