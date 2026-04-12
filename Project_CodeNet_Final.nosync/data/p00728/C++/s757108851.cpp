#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<int> a(n);
        in_arr(int, a, n);
        sort(a.begin(), a.end());
        int sum = 0;
        for(int i = 1; i < n - 1; ++i){
            sum += a[i];
        }
        cout << sum / (n - 2) << endl;
    }
    return 0;
}

