#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#define MOD 1000000007
using namespace std;

int main(void){
    int n;
    string s;
    int k;
    cin >> n >> s >> k;
    for(int i=0; i<n; i++){
        if(s[i]!=s[k-1])s[i]='*';
    }
    cout << s << endl;
    return 0;
}