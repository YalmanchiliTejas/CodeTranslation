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

//#include<bits/stdc++.h>


using namespace std;
int main()
{
    
    int n;
    cin >> n;
    vector<int>p(n);
    int ans = 0;
    int t = -1;
    for (int i = 0; i < n; i++) { 
        cin >> p[i];
        if (p[i] >= t) {
            ans++; t = p[i];
        }
    }

    cout << ans << endl;


    return 0;

}
