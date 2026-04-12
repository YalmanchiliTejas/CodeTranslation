//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <vector>
#include <numeric>
#include<string>
#include <map>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ll long long
#define rep(cnt,a,n) for(ll cnt=a;cnt<n+a;cnt++) //aから始めてn回ループ
#define vector2(type,name,a,b) vector<vector<type>> name(a, vector<type>(b))
#define PI 3.141592653589793





int main() {
    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
