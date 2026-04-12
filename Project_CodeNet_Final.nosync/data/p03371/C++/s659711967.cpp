#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int money1;
    if(min(X,Y) == X) money1 = C*2*X + (Y-X)*B;
    else money1 = C*2*Y + (X-Y)*A;
    int money2 = C*2*max(X,Y);
    int money3 = A*X + B*Y;
    
    cout << min(money1, min(money2,money3)) << endl;

	return 0;
}