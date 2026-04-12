#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int n, ai;
vector<int> data;
signed main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    if (n % 2 == 0){
        for (int i=n-1;i>=0;i-=2){
            cout << data[i] << " ";
        }
        for (int i=0;i<n;i+=2){
            cout << data[i] << " ";
        }
    }
    else{
        for (int i=n-1;i>=0;i-=2){
            cout << data[i] << " ";
        }
        for (int i=1;i<n;i+=2){
            cout << data[i] << " ";
        }
    }
    return 0;
}
