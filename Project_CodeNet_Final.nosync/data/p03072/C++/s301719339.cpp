#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int h[20] = {};

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int max = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(max <= h[i]){
            count++;
            max = h[i];
        }
    }

    cout << count << endl;
}
