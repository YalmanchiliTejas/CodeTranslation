#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

ll pate[52],pan[52];

int main()
{
	ll n,x;
	cin >> n >> x;
	pate[0] = 1;
	pan[0] = 1;
	for(int i=0;i<51;i++)
	{
		pate[i+1] = pate[i]*2+1;
		pan[i+1] = pan[i]*2+3;
	}
	//cout<<pan[2]<<endl;
	ll ans = 0;
	for(int i =n;i>=0;i--)
	{
		if(x>pan[i]/2)
		{
			ans += pate[i]/2+1;
			x-= pan[i]/2+1;
		}
		else
		{
			x--;
		}
	}
	cout<<ans<<endl;
	return 0;
}