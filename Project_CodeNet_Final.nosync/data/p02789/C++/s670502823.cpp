#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    if (N == M){
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }

    return 0;
}