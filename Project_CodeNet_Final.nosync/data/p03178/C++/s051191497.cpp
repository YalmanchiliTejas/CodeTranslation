#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXD = 123;
const int MAXK = 112345;
const int mod = 1000000000+7;

char ent[MAXK];
int d, strSize;
int pd[MAXK][MAXD][2];

int rec(int cur, int sum, int last_digit_gt)
{
	// cout << last_digit_gt << " -- " << sum << endl;
	if(cur==strSize){
		if(sum % d==0) return 1;
		else return 0;
	}

	if(pd[cur][sum][last_digit_gt]!=-1)
		return pd[cur][sum][last_digit_gt];

	int acum = 0;
	int lim = last_digit_gt ? (ent[cur]-'0') : 9;
	for(int i=0; i<=lim; i++){
		// cout << cur << " // " << i << endl;
		int next_last_digit = last_digit_gt && (i == lim);
		acum += rec(cur+1, (sum+i)%d, next_last_digit);
		acum = acum%mod;
	}

	return pd[cur][sum][last_digit_gt] = acum;
}

int main()
{
	scanf("%s\n%d", ent, &d);
	strSize = strlen(ent);

	memset(pd, -1, sizeof(pd));

	int resp = 0;
	for(int i=0; i<(ent[0]-'0'); i++){
		resp += rec(1,i%d,0);
		resp = resp%mod;
	}
	resp += rec(1,(ent[0]-'0')%d,1);
	resp = resp%mod;

	cout <<  ((resp-1) % mod  < 0 ? (resp-1) % mod + mod : (resp-1) % mod) << '\n';

	return 0;
}