#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll infll=9223372036854775806;
const int inf=2147483646;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k,i;
	string a;
	cin>>n>>a>>k;
	for (i=0;i<a.size();i++){
		if (a[i]!=a[k-1]){
			cout<<"*";
		}
		else {
			cout<<a[i];
		}
	}
	return 0;
}