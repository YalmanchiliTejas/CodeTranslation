#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}
