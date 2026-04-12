#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>
#include <set>
#include <ios>
#include <iomanip>
#include <functional>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i = 0; i < n; i++){
        if(s[i] != s[k - 1]){
            s[i] = '*';
        }
    }
    cout << s;
}
