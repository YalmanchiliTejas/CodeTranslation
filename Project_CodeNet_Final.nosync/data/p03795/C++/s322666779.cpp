#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	int n;
	cin >> n;


	long long zx = n * 800;
	int rem = n / 15;
	cout << zx - rem * 200 << endl;


	return 0;
}