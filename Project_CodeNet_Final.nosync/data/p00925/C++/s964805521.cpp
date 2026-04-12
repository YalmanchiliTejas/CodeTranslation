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
#include <stack>
#include <tuple>
#include <array>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)


typedef long long int ll;
typedef double D;      // ??§?¨?????????????double???long double?????????
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;


const int INF = (1<<30) - 1;
const D EPS = 1e-9;

#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

string S;
int ans;
int cur;

int term(){
    int n = S[cur++] - '0';
    if(S[cur] == '*'){
        cur++;
        n *= term();
    }
    return n;
}

int expression(){
    int n = term();
    if(S[cur] == '+'){
        cur++;
        n += expression();
    }
    return n;
}

int left_to_right(){
    int tans = S[0] - '0';
    for(int i=1; i<S.length(); i+=2){
        int n = S[i+1] - '0';
        if(S[i] == '+')
            tans += n;
        else // *
            tans *= n;
    }
    return tans;
}

void solve(){
    cur = 0;
    
    char table[2][2] = {{'I', 'M'}, {'L', 'U'}};
    
    bool is_left_to_right = left_to_right() == ans;
    bool is_multiplication_first = expression() == ans;
    
    cout << table[is_left_to_right][is_multiplication_first] << endl;
}

//g++ -std=c++0x -msse4.2 -O3
//#include <bits/stdc++.h>
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(16);
    
    cin >> S >> ans;
    solve();
    
    return 0;
}