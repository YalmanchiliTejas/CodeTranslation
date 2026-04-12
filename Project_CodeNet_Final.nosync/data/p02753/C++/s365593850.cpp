#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)



int main() {
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}