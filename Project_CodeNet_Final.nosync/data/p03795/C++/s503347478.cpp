#include <iostream>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    if((N/15) == 0)
        cout << N * 800 << endl;
    else
        cout << N * 800 - (200 * (N / 15)) << endl;
    
}