#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int h[20];
    int max_height = 0;
    int hotel = 0;
    for (int i=0; i < n; i++){
        cin >> h[i];
        if (h[i] >= max_height){
            max_height = h[i];
            hotel += 1;
        }
    }
    cout << hotel << endl;
}