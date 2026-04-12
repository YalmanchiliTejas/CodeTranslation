#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define make0(a) memset(a,0,sizeof(a))
#define make1(a) memset(a,-1,sizeof(a))
#define all(v) begin(v),end(v)
#define allr(v) v.rbegin(),v.rend()
#define pi pair <int,int>
#define pll pair <ll,ll>
#define fast_cin() ios_base::sync_with_stdio(0) 

const int mod = 1e9+7;

void print(int *A, int N)
{
	for(int i=0;i<N;i++)
		cerr << A[i] << " ";
	cerr << endl;
}

int main()
{
	// #ifdef ONLINE_JUDGE 
	// 	freopen("input.txt", "r", stdin); 
	// 	freopen("output.txt", "w", stdout); 
	// #endif

	fast_cin();
	int N;
	cin >> N;
	int A[N+1];
	for(int i=1;i<=N;i++)
		cin >> A[i];
	if(N%2 == 0)
	{

		for(int i=N; i>=1; i-=2)
			cout << A[i] << " ";
		for(int i=1;i<=N;i+=2)
			cout << A[i] << " ";


	}
	else
	{

		for(int i=N; i>=1; i-=2)
			cout << A[i] << ' ';
		for(int i=2;i <= N; i+=2)
			cout << A[i] << " ";

	}
	cout << endl;
	return 0;
}