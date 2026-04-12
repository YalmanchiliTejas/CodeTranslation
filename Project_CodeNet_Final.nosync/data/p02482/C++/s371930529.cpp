#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cctype>
#include <numeric>
#include <cstring>
#include <bitset>
#include <complex>
#include <complex>

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    os << "{ ";
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
        os << '\"' << *it << '\"' << (it + 1 == v.end() ? "\"" : " ");
    os << " }";
    return os;
}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long ul;
typedef unsigned long long ull;

#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define loop(i,a,b) for(ull i=(a); i<(ull)(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back
#define mp make_pair
string const resstr[] = { "Impossible", "Possible", "No", "Yes" };

int main(){
    int a, b;
    cin >> a >> b;
    cin >> a >> b;
    if (a > b) cout << "a > b" << endl;
    else if (a == b) cout << "a == b" << endl;
    else if (a < b) cout << "a < b" << endl;
}