#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <cctype>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    string s;
    int n,k;
    cin >> n >> s >> k;
    rep(i,s.size()) if(s.at(i) != s.at(k-1)) s.at(i)='*';
    cout << s << endl;
}