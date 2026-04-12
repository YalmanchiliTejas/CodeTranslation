#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+18
#define MOD 1000000007
using namespace std;



int main(){
    double r1,r2;
    cin >> r1 >> r2;
    
    cout<<fixed<<setprecision(6)<<(r1*r2)/(r1+r2)<<endl;
    return 0;
}
