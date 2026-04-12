#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int N;
    
    cin >> N;
    
    if(N == 7 || N == 5 || N == 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
