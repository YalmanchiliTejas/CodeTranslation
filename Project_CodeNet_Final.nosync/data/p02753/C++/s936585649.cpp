#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long int ll;

#define PI (acos(-1))
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define dumparr(x) cerr << #x ; for(auto elem: x){cerr << " " << elem;} cerr << endl;
#define dumppairs(x) cerr << #x ; for(auto elem: x){cerr << "(" << elem.first << " " << elem.second << ") ";} cerr << endl;
#define dumpline cerr << "**********************" << endl;
#define dumpwline(x) cerr << "******** " << #x << "=" << (x) << " ********" << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(void){
    string s; cin >> s;
    REP(i, s.size()-1){
        if (s[i] != s[i+1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}