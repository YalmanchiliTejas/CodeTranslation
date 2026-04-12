#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define INF 1000000
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
using namespace std;
int main()
{
	char c;
	cin >> c;
	char check[] = {'a', 'e', 'i', 'o', 'u'};
	for(int i = 0; i < 5; i++)
	{
		if(c == check[i])
		{
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}

