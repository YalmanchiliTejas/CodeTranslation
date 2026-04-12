#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <typeinfo>
    
using namespace std;
    
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i,n) cin >> s[i];
    // minimum size
    int p=0;
    REP(i,n) if(s[i].size() < s[p].size()) p = i;
    string mn_s, inp;
    mn_s = s[p];
    
    // find common chars
    for(int i=0; i<mn_s.size(); i++){
        int ok=1;
        for(int j=0; j<n; j++){
            if((int)s[j].find(mn_s[i]) == -1){
                ok = 0;
                break;
            }
        }
        if(ok){
            inp += mn_s[i];
            for(int j=0; j<n; j++){
                s[j].erase(s[j].begin() + (int)s[j].find(mn_s[i]));
            }  
        }
    }
    for(int i=0; i<inp.size(); i++){
        for(int j=0; j<inp.size()-1; j++){
            if(inp[j] > inp[j+1]) swap(inp[j], inp[j+1]);
        }
    }
    cout << inp << endl;
} 