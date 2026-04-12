#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(x.begin(), x.end());
    for(int i = 0; i < n; i++){
        auto itr = lower_bound(x.begin(), x.end(), y[i]);
        //cout << "y: " << y[i] << endl;
        //cout << "itr: " << itr-x.begin() << endl;
        if(itr-x.begin() < n/2){
            if(itr-x.begin() == n/2){
                cout << x[n/2-1] << endl;
            }else{
                cout << x[n/2] << endl;
            }
        }else{
            cout << x[n/2-1] << endl;
        }
    }
    return 0;
}