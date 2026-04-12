#include <iostream>

using namespace std;

int main() {
    int n, a, b, c=1;
    cin >> n;
    cin >> a;
    for(int i=1;i<n;i+=1) {
        cin >> b;
        if (a <= b) {
            a = b;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}