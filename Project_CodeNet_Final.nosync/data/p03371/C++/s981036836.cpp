#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int A, B, C, X, Y;
int main(int argc, char const *argv[])
{
    cin >> A >> B >> C >> X >> Y;
    int first=A*X+B*Y;
    int second=C*2*X+max(Y-X,0)*B;
    int third=C*2*Y+max(X-Y,0)*A;
    int ans=min(first,min(second,third));
    cout<<ans<<endl;
    return 0;
}
