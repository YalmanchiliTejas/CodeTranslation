#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
const ll p=1e9+7;
int main()
{
	int r,g,b;
	cin>>r>>g>>b;
	int ans=(r*100+g*10+b)%4;
	if(ans)printf("NO");
	else printf("YES");
	return 0;
}
