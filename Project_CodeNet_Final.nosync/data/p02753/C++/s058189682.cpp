#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;

int main(){
    int i;
    int ans=0;
    char s[100];

    rep(i,0,3) {
        cin >> s[i];
    }

    if(s[0]==s[1]){
        if(s[0]==s[2]){
            ans =1;
        }
    }
    if(ans==0){
        cout << "Yes" << endl;
    }
    if(ans==1){
        cout << "No" << endl;
    }
    
}