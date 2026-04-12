#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iomanip>
using namespace std;
 
#define REP(i,n) for(long long (i)=0;(i)<(long long)(n);(i)++)
#define RREP(i,n) for(long long (i)=(long long)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;
 
int main() {
 
    string s; cin >> s;
    if (s.find("AC") != string::npos) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
    }
 
    return 0;
}