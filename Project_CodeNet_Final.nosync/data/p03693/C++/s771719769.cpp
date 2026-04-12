#include <bits/stdc++.h>

using namespace std;

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef long long ll; typedef vector<int> VI; typedef pair<ll,int> pii;
const ll mod = 1e9+7;


int main()
{
	
	//cin.tie(0); ios_base::sync_with_stdio(false);

	int r,g,b;
	cin >>r >>g >>b;
	ll su = r*100+g*10+b;
	if(su%4==0) puts("YES");
	else puts("NO");
	return 0;
}


