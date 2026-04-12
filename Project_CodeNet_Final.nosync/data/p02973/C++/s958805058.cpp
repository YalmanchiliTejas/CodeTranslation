#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }
    multiset<LL> s;
    for(LL i=0; i<n; i++){
        auto itr=s.lower_bound(a[i]);
        if(itr!=s.begin()){
            itr--;
            s.erase(itr);
        }
        s.insert(a[i]);
    }

    cout << s.size() << endl;

    return 0;
}
