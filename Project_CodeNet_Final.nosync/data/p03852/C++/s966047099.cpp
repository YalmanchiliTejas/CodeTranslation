#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MAX 3e5+7
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char c;
	cin >> c;
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
	{
		cout << "vowel";
	}
	else
	{
		cout << "consonant";
	}
	
	return 0;
}