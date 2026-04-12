#include <bits/stdc++.h>
using namespace std;
#define push_back emplace_back
#define int long long
typedef pair<int, int> pii; 
typedef vector<pii> vii;
typedef vector<int> vi;
#define ss second
#define ff first
#define pii pair<int, int>
#define max3(a, b, c) max(a, max(b, c))
#define TEST ll t; cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define pq priority_queue<int>
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}

void fastio()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main() {
	fastio();
	int n;
	cin>>n;
	if(n>=30)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	return 0;
}