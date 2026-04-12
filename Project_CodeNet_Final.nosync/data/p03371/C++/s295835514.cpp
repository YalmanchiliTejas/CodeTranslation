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
#include<fstream>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define out(str) cout << str << endl
#define ALL(a) (a).begin(),(a).end()
#define INF (1<<29)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int A,B,C,X,Y;

int main(){
    cin>>A>>B>>C>>X>>Y;
    out(min(X,Y)*min(A+B,C*2)+(X-min(X,Y))*min(A,C*2)+(Y-min(X,Y))*min(B,C*2));
    
}
