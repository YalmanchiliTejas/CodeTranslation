//47行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b);
template<class T> bool chmax(T& a,T b);
template<class T> void debugger(vector<T>& a);
template<class T> void debugger(vector<vector<T>>& a);
///////////////////////////////////////////////////////////

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(20);
    string s;cin >> s;
    if(s[1] != s[0] or s[1] != s[2])cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}

///////////////////////////////////////////////////////////
template<class T> bool chmin(T& a,T b){
    if(a > b){a = b;return true;}else return false;
}
template<class T> bool chmax(T& a,T b){
    if(a < b){a = b;return true;}else return false;
}
template<class T> void debugger(vector<T>& a){
    cerr << "{";
    for(int i = 0;i < a.size();i++){
        if(i == 0)cerr << a[i];
        else cerr << "," << a[i];
    }
    cerr << "}" << '\n';
    return;
}
template<class T> void debugger(vector<vector<T>>& a){
    int n = a.size();
    int m = a[0].size();
    cerr << "__|";
    for(int i = 0;i < m;i++){
        cerr << setw(5) << i;
    }
    cerr << '\n';
    for(int i = 0;i < n;i++){
        cerr << setw(3) << i;
        for(int j = 0;j < m;j++){
            if(a[i][j] >= 100000)cout << setw(5) << "INF";
            else cerr << setw(5) << a[i][j];
        }
        cerr << '\n';
    }
}
