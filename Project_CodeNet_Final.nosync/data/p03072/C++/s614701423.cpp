#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int height[n] = {0};
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    int max = height[0];
    for (int j = 0; j < n; ++j) {
        if(max <= height[j]){
            count++;
            max = height[j];
        }
    }

    cout<<count;
    return 0;
}