#include <iostream>
using namespace std;
int main() {
    int N,M;
    cin >> N >> M;
    string s="Yes";
    if (N>M) s="No";
    cout << s << endl;
    return 0;
}