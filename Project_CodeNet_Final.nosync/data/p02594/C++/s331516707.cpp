#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long ll;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f(i,a) for(int i = 0 ; i < a ; i++)
#define ff first
#define ss second
#define all(x) (x).begin() ,(x).end()

#define pb push_back
#define mp make_pair
#define numberofdigits(x) floor(log10(x)) + 1



int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	//cin >> t;

	while (t--)
	{
		int x;
		cin >> x;

		if (x >= 30)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}



