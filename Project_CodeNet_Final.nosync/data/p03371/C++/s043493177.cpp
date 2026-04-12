#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<queue>
#include<set>
#include<cstdio>
#include<climits>
#include<cstring>

using namespace std;

int main(){

    int A,B,C;
    cin >> A >> B >> C;
    int X,Y;
    cin >> X >> Y;

    int R = max(X,Y);

    int ans = INT_MAX;

    for(int i = 0;i <= R;i++){
    	ans = min(ans,(2*C*i + A*max(X-i,0) + B*max(Y-i,0)));
    }

    cout << ans << endl;

	return 0;

}
