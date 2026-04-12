#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int A, B ,C;
	cin >> A >> B >> C;
	int X, Y;
	cin >> X >> Y;
	LL ans=10000000000;
	rep(i,X+1){
		LL sum=0;
		sum+=A*i+C*(X-i)*2;
		if((X-i)<Y) sum+=B*(Y-(X-i));
		ans=min(ans,sum);
	}
	rep(i,Y+1){
		LL sum=0;
		sum+=B*i+C*(Y-i)*2;
		if((Y-i)<X) sum+=A*(X-(Y-i));
		ans=min(ans,sum);
	}
	cout << ans << endl;

	return 0;
}