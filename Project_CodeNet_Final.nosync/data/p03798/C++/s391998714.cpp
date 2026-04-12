#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
//#include <stack>
#include <climits>
#include <map>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
#define all(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

int n;
string s;

struct animal{
    char sheep,wolf;
};

ll comb(int a,int b){
    if(a<b)return 0;
    if(b>a-b) return comb(a,a-b);
    ll rtn=1;
    REP(i,b){
        rtn *= (a-i);
        rtn /= (i+1);
    }
    return rtn;
}

char rev(char c,char st,char an){
    if(an=='S'){
        if(st=='o'){
            if(c=='S'){
                return 'S';
            }else{
                return 'W';
            }
        }else{
            if(c=='S'){
                return 'W';
            }else{
                return 'S';
            }
        }
    }else{
        if(st=='o'){
            if(c=='S'){
                return 'W';
            }else{
                return 'S';
            }
        }else{
            if(c=='S'){
                return 'S';
            }else{
                return 'W';
            }
        }
    }
}

int main() {
    cin >> n >> s;
    //1番目と2番目をSまたはWと仮定するとそれに応じて1周分のSWが確定し、矛盾があるかどうかもわかる
    char sw[2][4] = {{'S','S','W','W'},{'S','W','S','W'}};
    string res;
    REP(i,4){
        res = "";
        res += sw[0][i];
        res += sw[1][i];
        FOR(j,1,n-1){
            res += rev(res[j-1],s[j],res[j]);
        }
        if(rev(res[n-2],s[n-1],res[n-1])==res[0]){
            if(rev(res[n-1],s[0],res[0])==res[1]){
                put(res);
                return 0;
            }
        }
    }
    put("-1");
    return 0;
}
