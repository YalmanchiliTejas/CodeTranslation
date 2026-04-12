#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=9223372036854775806;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if (x==y){
		cout<<x*min(a+b,2*c);
	}
	else if (x>y){
		cout<<y*min(a+b,2*c)+(x-y)*min(a,2*c);
	}
	else {
		cout<<x*min(a+b,2*c)+(y-x)*min(b,2*c);
	}
	return 0;
}