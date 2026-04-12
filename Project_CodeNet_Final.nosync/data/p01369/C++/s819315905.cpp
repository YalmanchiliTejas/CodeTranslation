#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <functional>
#include <complex>

using namespace std;

const int INF = (1<<30) - 1;

bool is_left(char c){
    string l = "qwertasdfgzxcvb";
    for(char v: l)
        if(c == v)
            return true;
    
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string s;
    
    while(cin>>s, s!="#"){
        int cnt = 0;
        for(int i=0; i<s.length()-1; i++){
            cnt += is_left(s[i])^is_left(s[i+1]);
        }
        cout << cnt << endl;
    }
    return 0;
}