#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int N,M[9999],big,ans=1;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> M[i];
	big = M[0];
	//カウント
	for (int i = 1; i < N; i++)
	{
		if (M[i] >= big){
			ans++;
			big = M[i];
		}
	}
	cout << ans << endl;
}