#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int x;
    cin >> x;
    if(x>=30) cout << "Yes" <<endl;
    else cout << "No" <<endl;
    
    return 0;
}
