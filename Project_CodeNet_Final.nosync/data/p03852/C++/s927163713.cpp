#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <deque>
using ll = long long;
using namespace std;

int main(){
    char c;
    string ans;
    cin >> c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ans = "vowel";
    else ans = "consonant";
    cout << ans << endl;
    return 0;
}
