#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization_level 3
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(){
	string s;
	cin>>s;
	if (s[0]!=s[1])
	{
		cout<<"Yes";
	} else if (s[1]!=s[2])
	{
		cout<<"Yes";
	} else
	{
		cout<<"No";
	}
	
	
	
}
