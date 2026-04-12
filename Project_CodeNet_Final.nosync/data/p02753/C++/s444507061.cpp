#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <functional>
 
using namespace std;
 
int main() {
    string s;
    cin>>s;
    bool a=s[0]=='A'||s[1]=='A'||s[2]=='A';
    bool b=s[0]=='B'||s[1]=='B'||s[2]=='B';
    if (a && b){
    cout<<"Yes";
    }else{
    cout<<"No";
}
}