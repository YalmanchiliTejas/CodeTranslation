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
    int n;
    cin >> n;
    vector<int> a(n);
    in_arr(int, a, n);
    list<int> b;
    rep(i, n){
        if(i % 2 == 0){
            b.push_back(a[i]);
        }else {
            b.push_front(a[i]);
        }
    }
    if(n % 2 == 1){
        for(list<int>::reverse_iterator i = b.rbegin(); i != b.rend(); ++i){
            cout << *i;
            if(next(i) == b.rend()){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }else {
        for(list<int>::iterator i = b.begin(); i != b.end(); ++i){
            cout << *i;
            if(next(i) == b.end()){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
    return 0;
}
