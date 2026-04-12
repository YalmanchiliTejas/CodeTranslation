#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> hvec;
    for(int i = 0 ; i < n ; i++){
        int height;
        cin >> height;
        hvec.push_back(height);
    }

    int result = 1;
    for(int i = 1 ; i < n; i++){
        if(hvec[i] == *max_element(hvec.begin(), hvec.begin() + i + 1)){
            result++;
        } 
    }

    cout << result;

    return 0;
}
