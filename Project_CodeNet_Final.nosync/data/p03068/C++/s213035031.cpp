#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n;
    string s;
    int k;
    cin >>  n >> s >> k;
    k--;
    for(int i = 0; i < n; i++){
        if(s[i] != s[k]) s[i] = '*';
    }
    cout << s << endl;
}