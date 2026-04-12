#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    int x,y;
    x=N*800;
    y=200*float(N/15);
    cout << x-y << endl;
    return 0;
}
