#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int main()
{
	MaRiaMa;
	int r=0, g=0, b=0,m=0;
	cin >> r>> g>> b;
	 m= (r* 100) + (g * 10) + b;
	if (m % 4 == 0)
		cout << "YES";
	else
		cout << "NO";
}
