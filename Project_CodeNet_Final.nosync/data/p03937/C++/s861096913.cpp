#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

char s[10][10];

int n,m,cnt=0;

void dfs(int x,int y) {
    --cnt;
    if(x==n && y==m) return;
    if(x<n && s[x+1][y]=='#') {
        dfs(x+1,y);return;
    }
    if(y<m && s[x][y+1]=='#') {
        dfs(x,y+1);return;
    }
}

int main() {
    read(n);read(m);
    REP(i,1,n) {
        scanf("%s",s[i]+1);
        REP(j,1,m) if(s[i][j]=='#') ++cnt;
    }
    dfs(1,1);
    if(cnt) printf("Impossible\n");
    else printf("Possible\n");
    return 0;
}