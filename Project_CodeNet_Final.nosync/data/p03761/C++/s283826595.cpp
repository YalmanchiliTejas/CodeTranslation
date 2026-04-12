#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#define INF 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main(){
    int n;
    cin>>n;
    int cnt[50][26]={};
    rep(i,n){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)cnt[i][s[j]-'a']++;
    }
    rep(i,26){
        int m=INF;
        rep(j,n){
            m=min(m,cnt[j][i]);
        }
        rep(j, m)cout<<(char)(i+'a');
    }
    cout<<endl;
    return 0;
}

