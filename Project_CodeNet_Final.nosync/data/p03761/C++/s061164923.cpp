#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define in(x) cin >> x
#define out(str) cout << str << endl

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int c[26][50];
int n,mini;
string S;

int main(){
    cin>>n;
    rep(i,n){
        cin>>S;
        rep(j,S.length()){
            c[S[j]-'a'][i]++;
        }
    }
    rep(i,26){
        mini=1e9;
        rep(j,n){
            mini=min(mini,c[i][j]);
        }
        rep(j,mini){
            cout<< char('a'+i);
        }
    }
    out("");
    
}
