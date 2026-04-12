#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>//小数点以下表示
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string a;
    cin>>a;
    if(a.at(0)=='A'&&a.at(1)=='A'&&a.at(2)=='A'){
        cout<<"No"<<endl;
    }
    else if(a.at(0)=='B'&&a.at(1)=='B'&&a.at(2)=='B'){
        cout<<"No"<<endl;
    }
    else {
        cout<<"Yes"<<endl;
    }
}