#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define SORT(v) sort(ALL(v))
//#define scanf scanf_s
typedef pair<int, int> P;

string l = "qwertasdfgzxcvb";
string r = "yuiophjklnm";
int hand[30];

int main()
{
	memset(hand, 0, sizeof(hand));
	REP(i, l.size())
	{
		hand[l[i] - 'a'] = 1;
	}
	string s;
	while (cin >> s)
	{
		if (s == "#") break;
		int cnt = 0;
		int buf = hand[s[0]-'a'];
		REP(i, s.size())
		{
			if (buf != hand[s[i]-'a'])
			{
				buf = hand[s[i]-'a'];
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}