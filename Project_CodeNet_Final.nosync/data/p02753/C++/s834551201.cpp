#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
int main(){
    string s;cin >> s;
    if(s=="AAA"||s=="BBB"){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}