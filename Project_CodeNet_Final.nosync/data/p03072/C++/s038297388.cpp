#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stdio.h>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>
#include <fstream>
#include <list>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    
    for (int i=0; i<n; i++){
        cin >> h[i];
    }
    int ans = 0;
    
    for (int i=0; i<n; i++){
        bool check = true;
        for (int j=0; j<i; j++){
            if (h[j] > h[i]){
                check = false;
                break;
            }
        }
        if (check){
           ans += 1;
        }
    }
    cout << ans <<endl;
}
