#include <iostream>
using namespace std;
int N, S;

int main()
{
    while ( cin >> N and N > 0) {
        int sum = 0;
        int largest = 0;
        int smallest = 1000;
        for (int i = 0; i < N; i++) {
            cin >> S;
            sum += S;
            if ( S > largest ) largest = S;
            if ( S < smallest ) smallest = S;
        }
        sum = sum - largest - smallest;
        int ave = sum / (N - 2);
        cout << ave << endl;
    }
    return 0;
}