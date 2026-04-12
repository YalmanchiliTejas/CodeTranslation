#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<vector>

using namespace std;


#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define ll long long
#define MOD 1000000007

#define IMIN INT_MIN;
#define IMAX INT_MAX;


int main(){
    string S;
    cin >> S;
    int acnt=0, bcnt=0;
    rep(i, S.size()) {
        if(S[i] == 'A') acnt++;
        else bcnt++;
    }
    if (acnt == 2 || acnt == 1) cout << "Yes" << endl;
    else cout << "No" << endl;


	return 0;
}
