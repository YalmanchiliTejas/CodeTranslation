#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <fstream>
#include <iterator>

#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v){
    if(!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}
//---------


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    //CLion Standard Input for DEBUG
    //--------------------------------------------------------------------------
//    ifstream in("/Users/ryo/Dropbox/competition/CompetitivePrograming/in.txt");
//    cin.rdbuf(in.rdbuf());
    //-------------------------------------------------------------------------

    int n;
    cin >> n;
    cout << 800 * n  - 200 * (n / 15)<< endl;

}