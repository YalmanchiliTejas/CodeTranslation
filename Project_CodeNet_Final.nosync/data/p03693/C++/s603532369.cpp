#include<cstdio>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
        string r,g,b; cin>>r>>g>>b;
        string s = r+g+b;
        int ans = stoi(s);
        cout << (ans%4==0 ? "YES":"NO") << endl;
        return 0;
}
