#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

using namespace std;

int main()
{
    string S;

    cin >> S;

    if(S == "AAA"){
        cout << "No" << endl;
    }
    if(S == "BBB"){
        cout << "No" << endl;
    }
    if(S == "AAB"){
        cout << "Yes" << endl;
    }
    if(S == "ABA"){
        cout << "Yes" << endl;
    }
    if(S == "BAA"){
        cout << "Yes" << endl;
    }
    if(S == "ABB"){
        cout << "Yes" << endl;
    }
    if(S == "BAB"){
        cout << "Yes" << endl;
    }
    if(S == "BBA"){
        cout << "Yes" << endl;
    }

    return 0;
}