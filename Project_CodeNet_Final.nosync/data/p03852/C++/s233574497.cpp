#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <numeric>
using namespace std;
int main(){
    string c;
    cin >> c;
    string ans;
    if(c=="a"||c=="i"||c=="u"||c=="e"||c=="o"){
        ans = "vowel";
    }else{
        ans = "consonant";
    }
    cout << ans << endl;
}