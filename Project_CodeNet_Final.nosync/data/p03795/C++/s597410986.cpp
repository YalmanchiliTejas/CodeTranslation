#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    int x=800*N, y=(N-N%15)/15*200;
    int ans = x-y;
    cout << ans << endl;
}