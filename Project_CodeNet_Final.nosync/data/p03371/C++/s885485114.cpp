
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define segment_size 65536
int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = A*X + B*Y;
    if(X >= Y){
        ans = min(ans, C*X*2);
        ans = min(ans, C*Y*2 + A*(X-Y));
    }
    else{
        ans = min(ans, C*Y*2);
        ans = min(ans, C*X*2 + B*(Y-X));
    }
    cout << ans << endl;

    return 0;
}
