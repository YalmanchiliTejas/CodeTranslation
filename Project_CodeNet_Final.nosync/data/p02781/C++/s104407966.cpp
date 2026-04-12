/*

Coded by peyha X

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NMAX = 1e3 + 1, KMAX = 3;

string n;
int k, m, compteurs[NMAX][KMAX], ans = 0;

int ncr(int k, int n)
{
	
	int ans = 1;
	for(int i = 0; i < k; i++)
	{
		ans *= (n - i);
	}
	for(int i = 0; i < k; i++)
	{
		ans /= (i + 1);
	}
	return ans;
}

int exp(int x,int n)
{
	if(n == 0)
		return 1;
	return x * exp(x, n - 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	
	m = n.size();
	
	//en mettant un 0 au debut
	//ans += ncr(k, m - 1);
	
	int non_zero = 0;
	for(int index = 0; index < m; index++)
	{
		//on a gardé les index - 1 premiers chiffres et on regarde ce qu'on peut mettre
		if(n[index] != '0')
		{
			non_zero ++;
			int digit = n[index] - '0', restant = m - index - 1, digit_restant = k - non_zero;
			//cout << digit << ' ' << restant << ' ' << digit_restant << '\n';
			
			ans += exp(9, digit_restant + 1) * ncr(digit_restant + 1, restant) + (digit - 1) * exp(9, digit_restant) * ncr(digit_restant, restant);
		} 
		
		if(non_zero == k)
		{
			ans ++;
			break;
		}
		
	}
	
	cout << ans << '\n';
	
	
}
