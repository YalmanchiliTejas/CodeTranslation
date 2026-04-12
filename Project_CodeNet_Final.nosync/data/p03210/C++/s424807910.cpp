#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=9223372036854775806;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	if (n==3||n==5||n==7){
		cout<<"YES";
	}
	else {
		cout<<"NO";
	}
	return 0;
}