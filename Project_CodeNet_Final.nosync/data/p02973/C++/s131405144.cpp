#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	ll a[n+1], c = 1;
	multiset <ll> ss;
	multiset <ll> :: iterator it;
	for(int i = 1; i < n+1; i++) cin >> a[i];
	ss.insert(a[1]);
	for(int i = 2; i < n+1; i++)
	{
		ss.insert(a[i]);
		if(ss.find(a[i]) == ss.begin()) c++;
		else
		{
		    it = ss.find(a[i]);
		    it--;
		    ss.erase(it);
		}
	}
	cout << c;
	// your code goes here
	return 0;
}
