//Dragon_warrior7(IITK)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define lb(v, temp) lower_bound(v.begin(), v.end(), temp)
#define ub(v, temp) upper_bound(v.begin(), v.end(), temp)
#define fi first
#define se second
#define llmax 1000000000000000000
#define deb(x) cout << #x << " " << x << "\n"
#define pll pair<ll, ll> 
#define vll vector<ll> 
#define rub cout << "\n------------------------------------\n"
void read(vector<ll> &v)
{
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
}

void print(vector<ll> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
ll n,m,a,b,temp,x,y;
string str;
set<ll> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	if(n==m)
	cout<<"Yes";
	else
	cout<<"No";
}