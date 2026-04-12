#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    int res=0;
    if ((A+B) <= 2*C){
	res=A*X+B*Y;
    } else {
	res+=2*C*min(X,Y);
	if (X > Y){
	    if (A > 2*C){
		res+=2*C*(X-Y);
	    } else {
		res+=A*(X-Y);
	    }
	} else {
	    if (B > 2*C){
		res+=2*C*(Y-X);
	    } else {
		res+=B*(Y-X);
	    }
	}
    }

    cout << res << endl;

    return 0;
}