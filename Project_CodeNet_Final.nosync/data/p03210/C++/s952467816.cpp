#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int a; cin >> a;
    if(a==3 || a==5 || a==7){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
