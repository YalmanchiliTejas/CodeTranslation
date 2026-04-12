#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
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

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
    
    string s;
    cin >> s; // s = "ABA"
    set <char> v;
    for (ll i=0;i<3;i++){
        v.insert(s[i]);
    }


    if(v.size() == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}