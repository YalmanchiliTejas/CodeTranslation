#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int h,w;
    cin >> h >> w;
    string s;
    int temp=0;
    rep(i,h){
        cin >> s;
        rep(j,w){
            if(s[j]=='#') temp++;
        }
    }
    if(temp==h+w-1){
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
