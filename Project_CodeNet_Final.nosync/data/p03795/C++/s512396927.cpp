#include <iostream>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    int x = N / 15; 

    int price = 800 * N - 200 * x;

    cout << price << endl;
}
