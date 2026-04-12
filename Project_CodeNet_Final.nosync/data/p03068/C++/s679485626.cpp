#include<iostream>
using namespace std;

int main()
{
	int N,K,i;
	char s[15];
	char hold,asta = '*';
	cin >> N >> s >> K;
	hold = s[K-1];

	for( i = 0; i < N; i++ )
  {
		if( hold != s[i] )
		{
			cout << asta;
		}else{
			cout << s[i];
		}
  }
	cout << endl;
	return 0;
}
