#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <bitset>
#include <math.h>
#include <numeric>
#include <stack>

using namespace std;
 
#define rep(i,m,n) for(int i=m;i<(int)(n);i++)
#define endl '\n'
typedef long long ll;

int gcd(int x,int y){
    return y ? gcd(y,x%y) : x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    rep(i,0,2){
        if(s[i]!=s[i+1]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
