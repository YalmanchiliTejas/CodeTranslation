#include <iostream>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    while((N<1||N>100)&&(M<0||M>N))
        cin >> N >> M;
    if (N == M)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
