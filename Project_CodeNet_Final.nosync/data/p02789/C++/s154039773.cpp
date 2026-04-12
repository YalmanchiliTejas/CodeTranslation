/*
Author : Vidish Joshi
*/

#include <bits/stdc++.h>
using namespace std;

//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
#define FOR1(i, m, n) for(i=m; i<n; i++)
#define FOR2(i, n, m) for(i=n-1; i>=m; i--)
#define v(v) ll v; cin>>v
#define mod 1000000007
#define mod2 998244353
#define mp make_pair
#define pb push_back
#define fill(a) memset(a, 0, sizeof(a))
#define start ll t; cin>>t; while(t--)

void re() {}
template <typename T, typename... args>
void re(T &x, args &... tail)
{
    cin >> x;
    re(tail...);
}
void pr() {}
template <typename T>
void pr(const T &x)
{
    cout << x;
}
template <typename T, typename... args>
void pr(const T &x, const args &... tail)
{
    cout << x << " ";
    pr(tail...);
}
template <typename... args>
void prln(const args &... tail)
{
    pr(tail...);
    cout << "\n";
}


int main(){
	FIO;
	int n, m;
	cin>>n>>m;
	if(n==m){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}


	return 0;
}
