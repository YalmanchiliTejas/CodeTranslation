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

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    int n;
    cin >> n;
    vector<int> a(n), sorted(n);
    in_arr(int, a, n);
    copy(a.begin(), a.end(), sorted.begin());
    sort(sorted.begin(), sorted.end());
    int mid = sorted[(sorted.size() + 1) / 2 - 1];
    repi(i, a){
        if(*i < mid && a.size() % 2 == 1){
            cout << mid << endl;
        }else if(a.size() % 2 == 1){
            cout << sorted[sorted.size() / 2 - 1] << endl;
        }else if(*i <= mid){
            cout << sorted[sorted.size() / 2] << endl;
        }else{
            cout << mid << endl;
        }
    }
    return 0;
}
