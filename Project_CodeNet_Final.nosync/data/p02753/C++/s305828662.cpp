#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;

string s;
int main(){
    cin>>s;
    if(s[0] == s[1] && s[1]== s[2]) puts("No");
    else puts("Yes");

    return 0;
}