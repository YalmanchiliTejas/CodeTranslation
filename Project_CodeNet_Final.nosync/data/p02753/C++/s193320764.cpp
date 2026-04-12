#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	cout<<((s[0]==s[1]&&s[1]==s[2])?"No":"Yes")<<endl;	
	return 0;
}