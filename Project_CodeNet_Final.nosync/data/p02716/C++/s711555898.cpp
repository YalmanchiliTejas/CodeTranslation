#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    vector<long long> p(n + 1), d(n + 1);
    p[1] = a[1];
    for(int i = 2; i <= n; ++i) p[i] = p[i - 2] + a[i];

    for(int i = 2; i <= n; ++i){
        if(i % 2){
            d[i] = max(d[i - 1], d[i - 2] + a[i]);
        }
        else{
            d[i] = max(p[i - 1], d[i - 2] + a[i]);
        }
    }

    cout << d[n];
}
