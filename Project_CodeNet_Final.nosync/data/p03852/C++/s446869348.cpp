#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<deque>

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e8;

using namespace std;

#define vvint(vec,n,m,l) vector<vector<int>> vec(n,vector<int>(m,l));
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>;
#define pint pair<int,int>;
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	char c;
	cin >> c;

	string s = { 'a','i','u','e','o' };
	rep(i, 5)
	{
		if (c == s[i])
		{
			cout << "vowel";
			break;
		}
		if (i == 4)
		{
			cout << "consonant";
		}
	}
	cout << endl;

}