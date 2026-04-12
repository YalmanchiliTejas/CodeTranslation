#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int result = 0;
    int a = h[0];
    for(int i = 0; i < n; i++){
        if(a <= h[i]){
            result++;
            a = max(a, h[i]);

        }
    }
    cout << result << endl;
}