#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define LL long long
using namespace std;

int main(void){
    int n;
    int max = 0;
    int result = 1;
    vector<int> h;

    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        h.push_back(tmp);
    }
    max = h[0];
    for (int i = 1; i < n; i++){
        if(max <= h[i]){
            max = h[i];
            result++;
        }
    }
    cout << result << endl;
}