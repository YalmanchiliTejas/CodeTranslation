#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main (){
    int n;
    cin >> n;
    int h[30];
    for (int i = 0; i < n; i++) cin >> h[i];
    int count = 0;
    for (int i = 0; i < n; i++){
        int count2 = 0;
        for (int j = 0; j < i; j++){
            if (h[j] <= h[i]) count2++;
        }
        if (count2 == i) count++;
    }
    cout << count << endl;
  return 0;
}
