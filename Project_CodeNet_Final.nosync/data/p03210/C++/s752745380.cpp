#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <map>
#define MAX_N 100
#define INF 10000000

using namespace std;

string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int n,m,a,b;
int N[100];
string s,t;

void solve() {
    if(n==7 || n==5 || n==3){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
	cin>>n;
	solve();
	return 0;
}