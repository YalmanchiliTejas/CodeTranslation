#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp make_pair
#define fi first
#define se second
#define pt(num) cout << num << "\n"
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll N;
string s;

char hoge(char a, char b, char c) {
    if(a=='S' && b=='S' && c=='o') return 'S';
    if(a=='S' && b=='S' && c=='x') return 'W';
    if(a=='S' && b=='W' && c=='o') return 'W';
    if(a=='S' && b=='W' && c=='x') return 'S';
    if(a=='W' && b=='S' && c=='o') return 'W';
    if(a=='W' && b=='S' && c=='x') return 'S';
    if(a=='W' && b=='W' && c=='o') return 'S';
    if(a=='W' && b=='W' && c=='x') return 'W';
    return ' ';
}

void pstr(char *p) {
    for(ll i=0; i<N; i++)
        cout << p[i];
    cout << "\n";
}

int main(void) {
    cin >> N;
    cin >> s;
    char ans[N];
    ll i;
    
    ans[0]='S';
    if(s[0]=='o') {
        ans[1]='S';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='S' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
        
        ans[1]='W';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='W' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
    }else if(s[0]=='x') {
        ans[1]='S';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='W' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
        
        ans[1]='W';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='S' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
    }
    
    ans[0]='W';
    if(s[0]=='o') {
        ans[1]='S';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='W' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
        
        ans[1]='W';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='S' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
    }else if(s[0]=='x') {
        ans[1]='S';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='S' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
        
        ans[1]='W';
        for(i=1; i<N-1; i++) {
            ans[i+1]=hoge(ans[i-1], ans[i], s[i]);
        }
        
        if(ans[N-1]=='W' && hoge(ans[N-2], ans[N-1], s[N-1])==ans[0]) {
            pstr(ans);
            return 0;
        }
    }
    
    pt(-1);
}





