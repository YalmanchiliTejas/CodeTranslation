#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lli long long int
#define REP1(i, n) for(lli i = 0; i < n; i++)
#define REP2(i, n) for(lli i = 1; i <= n; i++)
#define pb push_back
#define ff first
#define ss second
#define pr pair<lli, lli>
#define mp make_pair
#define vi vector<lli>
#define mii map<lli, lli>
#define mod 1000000007
     
void solution()
{
	lli n;
	cin >> n;
	if(n < 30)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("Input.txt", "r", stdin);
    // for writing output to output.txt 
    freopen("Output.txt", "w", stdout);
  	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	//cin >> t;
	//while(t--)
		solution();
	return 0;
}
	