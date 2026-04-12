#include<algorithm>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<iostream>
#include<map>
#include <queue>
#include<string>
#include<vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define out(x) cout << x << endl;
#define each(e, v) for (auto&& e : v)
#define clamp(v,lo,hi) min(max(v,lo),hi)
#define debug(i) cout<<"point :"<< i << endl;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define all(a) a.begin(),a.end()
typedef long long LL;
typedef vector<int> vint;
typedef vector<long> vl;
typedef vector<double> vdouble;
typedef vector<string> vstr;
typedef vector<bool> vbool;
typedef map<string, int> mapstri;
typedef map<int, int> mapii;
typedef std::pair<int, int> pairii;

int main () {
    string s;
    cin >> s;
    if (s != "AAA" && s != "BBB") {
        out("Yes")
    } else {
        out("No")
    }
    return 0;
}