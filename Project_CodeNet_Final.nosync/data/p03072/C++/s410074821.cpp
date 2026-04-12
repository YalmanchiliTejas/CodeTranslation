#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;

    int h;
    int ans = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> h;
        if(h >= max){
            max = h;
            ans += 1;
        }
    }

    cout << ans << endl;

}