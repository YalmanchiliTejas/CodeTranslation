#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
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
#include <new>
#include <typeinfo>

typedef  long long ll;
#define mop 1000000007
#define mop2 998244353
using namespace std;


int main() {
    

    ll n;
    cin >> n;
    vector <ll> a;
    for(ll i=0;i<n;i++){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    reverse(a.begin(), a.end());
    vector <ll> v;
    if(n%2 == 0){
        for(ll i=0;i<n;i++){
            if(i < 2){
                v.push_back(a[i]);
            }else{
                if(i%2 == 0){
                    v.push_back(a[i] + v[i-2]);
                }else{
                    v.push_back(a[i] + max(v[i-2], v[i-3]));
                }
            }
        }
        reverse(v.begin(), v.end());
        cout << max(v[0], v[1]) << endl;
    }else{
        for(ll i=0;i<n/2 * 3;i++){
            if(i < 3){
                v.push_back(a[i]);
            }else{
                if(i%3 == 0){
                    v.push_back(a[i - i/3] + v[i-3]);
                }else if(i%3 == 1){
                    v.push_back(a[i - i/3] + max(v[i-3], v[i-4]));
                }else{
                    v.push_back(a[i-i/3] + max(v[i-3], max(v[i-4], v[i-5])));
                }
            }
        }
        reverse(v.begin(), v.end());
        cout << max(v[0], max(v[1], v[2])) << endl;
    }



}