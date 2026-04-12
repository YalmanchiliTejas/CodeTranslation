#include <iostream>
using namespace std;

int RestaurantCalculation(int n){
    int sum = 0;
    sum += n * 800;
    sum -= (n - n % 15) / 15 * 200;
    return sum;
}

int main() {
    int N;
    cin >> N;
    int x;
    x = RestaurantCalculation(N);
    cout << x << endl;
    return 0;
}
