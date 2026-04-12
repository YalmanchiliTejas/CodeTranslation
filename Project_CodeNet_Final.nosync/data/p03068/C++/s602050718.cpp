// Contest.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include"iostream"
#include"string"
#include"vector"
#include"algorithm"

using namespace std;

int main()
{
	int n,k;
	cin >> n;
	vector<char>s(n);
	for (int j = 0; j < n; j++)  cin >> s[j];
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != s[k-1]) {
			s[i] = '*';
		}
	}

	for (int l = 0; l < n; l++)
	{
		cout << s[l] ;
	}

	return 0;
}




