/* D-"Median of Medians" */
/*  */
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#define ll long long
#define N_MAX 100000
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No";
    } else
    {
        cout << "Yes";
    }
    

    return 0;
}