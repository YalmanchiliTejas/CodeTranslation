#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int a,b,c,x,y,ret=INT_MAX; cin>>a>>b>>c>>x>>y;
	for (int ab=0; ab<=2*max(x,y); ab+=2)
		ret=min(ret,ab*c+max(0,x-ab/2)*a+max(0,y-ab/2)*b);
	cout<<ret<<"\n";
	return 0;
}