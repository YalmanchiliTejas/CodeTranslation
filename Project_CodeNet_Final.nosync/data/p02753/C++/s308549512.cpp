#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    string s; cin >> s;
    if(s.at(1)==s.at(2) && s.at(0)==s.at(1)){
        cout << "No" << endl;
    }else{
        cout << "Yes" <<endl;
    }
}