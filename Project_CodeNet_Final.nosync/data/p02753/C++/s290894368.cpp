#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;



int main()
{

    string p;
    cin >> p;
    set<char>t;

    for (int i = 0; i < p.size(); i++) {
        t.insert(p[i]);
    }
    if (t.size() <= 1)cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;

}