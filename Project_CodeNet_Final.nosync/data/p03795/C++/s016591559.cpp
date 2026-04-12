#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    int ans = 800*N - (N/15)*200;
    cout << ans << endl;

    return 0;
}