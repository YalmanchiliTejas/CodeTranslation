#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) {
    return (a >= b) ? a : b;
}

/*int main() {
    vector<long long> value;
    long long A,B,C;
    int X,Y;

    cin >> A >> B >> C >> X >> Y;

    for ( int i = 0; i <= max(X,Y); ++i ) {
        value.push_back(2*C*i + A * max(0,X-i) + B * max(0,Y-i));
    }

    sort(value.begin(),value.end());
    cout << "sort completed!" << endl;

    cout << value[0] << endl;

    return 0;

}*/

int main() {
    long long A,B,C;
    int X,Y;

    cin >> A >> B >> C >> X >> Y;

    long long min;
    min = A * X + B * Y;
    for ( int i = 1; i <= max(X,Y); ++i ) {
        if ( (2*C*i + A * max(0,X-i) + B * max(0,Y-i)) < min ) min = (2*C*i + A * max(0,X-i) + B * max(0,Y-i));
    }

    cout << min << endl;

    return 0;
}