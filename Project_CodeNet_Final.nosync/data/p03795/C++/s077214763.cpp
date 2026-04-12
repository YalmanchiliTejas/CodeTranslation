#include <iostream>

#define ONE 800
#define SET (ONE * 15 - 200)

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << N / 15 * SET + N % 15 * ONE <<endl;
    return 0;
}