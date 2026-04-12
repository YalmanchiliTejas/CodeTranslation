#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#define PI 3.14159265358979323846

using namespace std;

int main()
{
	int N, K;
	string S;

	cin >> N >> S >> K;

	for(int i=0;i<N;i++)
	{
		if(S[i]!=S[K-1])
			S[i]='*';
	}
	cout << S << endl;

	return 0;
}