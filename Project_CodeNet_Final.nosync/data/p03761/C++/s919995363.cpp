#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <functional>

#define REP(i,a) for(int (i)=0;(i)<(a);i++)
#define RREP(i,a,b) for(int (i)=(a);(i)<(b);i++)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string S[n];
    int h[n][26]={};
    REP(i,n){
        cin>>S[i];
        REP(j,sz(S[i]))h[i][S[i][j]-'a']++;
    }
    string ans;
    REP(i,26){
        int tmp=100;
        REP(j,n)tmp=min(tmp,h[j][i]);
        REP(k,tmp)ans+='a'+i;
    }
    cout<<ans;
    return 0;
}