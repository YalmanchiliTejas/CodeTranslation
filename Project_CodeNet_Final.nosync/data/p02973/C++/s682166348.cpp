#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
   

    multiset <ll> s;
    ll n;
    cin >> n;
    for (ll i=0;i<n;i++){
        ll a;
        cin >> a;
        auto itr = s.lower_bound(a);
        if(itr == s.begin()){
            s.insert(a);
        }else{
            itr--;
            s.erase(itr);

            s.insert(a);
        }
//        cout << i << " ";
//        for(auto itr = s.begin(); itr != s.end(); itr++){
//            cout << *itr << " ";
//        }
//        cout << endl;
    }
    cout << s.size() << endl;
}