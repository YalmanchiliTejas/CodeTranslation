//By Don4ick
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;


string s[10];
int n, m , cnt;

int get(int i,int j){
	if(i < n && j < m)
    	return max(get(i + 1, j), get(i, j + 1)) + (s[i][j] == '#');
	else
		return 0;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < m; j++)
			if(s[i][j] == '#')
				cnt++;
	}
	for(int i = 0;i < n; i++)
		for(int j = 0; j < m; j++)
			if(get(i, j) == cnt)
				cout << "Possible", exit(0);
	cout << "Impossible";
    return 0;
}
