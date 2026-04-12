#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	cout << min(max(x,y)*2*c,min(a*x+b*y,x>y?y*2*c+(x-y)*a:x*2*c+(y-x)*b))<<endl;
}