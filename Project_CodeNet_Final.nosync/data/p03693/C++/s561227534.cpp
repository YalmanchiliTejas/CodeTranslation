#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=1ll<<60;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	if ((a*100+b*10+c)%4==0){
		cout<<"YES";
	}
	else {
		cout<<"NO";
	}
	return 0;
}