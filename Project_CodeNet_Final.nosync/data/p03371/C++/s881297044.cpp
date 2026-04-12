#include <iostream>
#include<math.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
        int A, B, C, X, Y;
        int Min;
        int ans=0;

        cin >> A >> B >> C >> X >> Y;

        Min=min(X,Y);

        ans+=min({X*A+Y*B,Min*2*C+(X-Min)*A+(Y-Min)*B,Min*2*C+(X+Y-2*Min)*2*C});

        cout << ans <<endl;
        return 0;
}
