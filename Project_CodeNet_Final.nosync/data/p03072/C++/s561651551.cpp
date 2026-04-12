#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

void In(ll& I)
{
	cin >> I;
}

void In(vl& I)
{
	for (auto& i : I)
	{
		cin >> i;
	}
}

void Out(ll& O)
{
	cout << O;
}

void Out(vl& O)
{
	for (auto& o : O)
	{
		cout << o;
	}
}

int main()
{
	ll N;
	In(N);

	vl H(N);
	In(H);

	ll M = 1;

	for (int i = 1; i < N; i++)
	{
		bool See = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (H[j] > H[i])
				See = false;
		}
		if (See)M++;
	}

	Out(M);
	return 0;
}