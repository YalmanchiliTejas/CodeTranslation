#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C,X,Y,ans;
int main(){
	cin >> A >> B >> C >> X >> Y ;
	ans = C * (max(X, Y) * 2);
	if (X <= Y){
		swap(A,B);swap(X,Y);
	}
	for(int i = 0; i <= Y; i++) 
    ans = min(ans, (i * B) + (A * (i+(X-Y))) + C*2*(Y-i));
    cout << ans;
    return 0;
}