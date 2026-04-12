#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}
int lcm(int a,int b){
    return b / gcd(a,b) * a;
}


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0;i < n;i ++) cin >> s.at(i);

    vector<vector<int> > a(n,vector<int>(26));

    for(int i = 0;i < n;i ++){
        for(int j = 0;j < s.at(i).size();j ++){
            a.at(i).at(s.at(i).at(j) - 'a') ++;
        }
    }

    vector<int> count(26,100);
    for(int i = 0;i < 26;i ++){
        for(int j = 0;j < n;j ++){
            count.at(i) = min(count.at(i),a.at(j).at(i));
        }
    }

    string ans = "";
    for(int i = 0;i < 26;i ++){
        for(int j = 0;j < count.at(i);j ++){
//            char b = 'a' + i;
            ans += 'a' + i;
        }
    }

    cout << ans << endl;
}