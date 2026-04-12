#include <bits/stdc++.h>

using namespace std;



int main()
{
	int n, contador = 1, max_altura;
	
	cin >> n;
	int altura[n];
	
	for ( int i = 0; i < n; ++i ) cin >> altura[i];
	max_altura = altura[0];
	for ( int i = 1; i < n; ++i )
	{
		if ( altura[i] >= max_altura )
		{
			max_altura = altura[i];
			contador++;
		}
	}
	
	cout << contador;
	return 0;
}