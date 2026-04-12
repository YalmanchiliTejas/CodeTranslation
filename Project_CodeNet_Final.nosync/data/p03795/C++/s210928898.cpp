#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int ans = 800 * N;
    while(N >= 15){
        ans -= 200;
        N -= 15;
    }
    
    cout << ans << endl;
}