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
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    long long c = 1;
    multiset<long long> s;
    s.insert(a[n - 1]);
    for(int i = n - 2; i >= 0; --i){
        auto now = s.upper_bound(a[i]);
        if(now == s.end()){
            c++;
            s.insert(a[i]);
        }
        else{

            s.erase(now);
            s.insert(a[i]);
        }
    }
    cout << c;
}
