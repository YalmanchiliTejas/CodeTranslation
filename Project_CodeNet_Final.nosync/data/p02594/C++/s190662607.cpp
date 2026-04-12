#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define forn(i,n) for(int i=0;i<n;i++)
#define rforn(i,n) for(int i=n-1;i>=0;i--)
#define mod (int)(1e9+7)
#define T int
#define pi pair<int,int>
#define umap unordered_map<T,T>
#define uset unordered_set<T>
#define ff first
#define ss second
#define vi vector<int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define setbit(n) __builtin_popcount(n)
#define toUpper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define toLower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)


int lcm(int a, int b)
{
	return (a / __gcd(a, b) * b);
}


int32_t main() {

	flash;
	cout << fixed;
	cout.precision(10);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t; cin >> t;
	int t=1;
	while (t--) {
		int n;cin>>n;
		if(n>=30){
			cout<<"Yes"<<endl;
		}
		else
			 cout<<"No"<<endl;

		

	}



	return 0;

}





