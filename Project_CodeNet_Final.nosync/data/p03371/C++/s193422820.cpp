#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1145141919
typedef long long int ll;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    vector<int> ans;

    REP(i,100001){
        ans.push_back( i*2*c + a*max(0,x-i) + b*max(0,y-i));
    }

    cout << *min_element(ans.begin(), ans.end()) << endl;

    return 0;
}