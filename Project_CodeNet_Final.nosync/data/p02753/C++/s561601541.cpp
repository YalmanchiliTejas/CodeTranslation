#include <bits/stdc++.h>

#include <iostream>


#define MOD 1000000007

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
auto f=[]()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
};

int main()
{
	f();
	string s;cin>>s;
	cout<<(s[0]==s[1]?((s[1]==s[2] || s[0]==s[2])?"No\n":"Yes\n"):"Yes\n");
	return 0;
}
