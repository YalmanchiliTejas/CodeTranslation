#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

struct Point {
    Point() {x=0,y=0;}
    Point(int _x,int _y){x  =_x,y=_y;}

    int x,y;
};

// 重载相应的比较运算符
bool operator < (Point a, Point b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
long long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char dc[] = {'R', 'L', 'D', 'U'};
char dcc[] = {'L', 'R', 'U', 'D'};

int k,n,m;

void solvee(){
    cin >> n >> m;
    vector<long long> c(n+1);
    vector<long long> res(n+1);
    vector<vector<long long> > nxt(n+1);
    for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for(int i = 0; i < m; i++) {
        int u,v;
        scanf("%d%d", &u,&v);
        res[u] += c[v];
        nxt[v].push_back(u);
    }
    long long ans = res[1];
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j < (1<<nxt[i].size()); j++) {
            cout << i<< ' '<< j<<endl;
            long long sum = c[i];
            for(int k = 0; k < nxt[i].size(); k++) {
                if(j&(1<<k)) {
                    sum += res[nxt[i][k]]-c[i];
                }
            }
            cout << "sum = " <<sum<<endl;
            ans = gcd(ans, sum);
        }
    }

    cout << ans <<endl;
}

char s[1000000+10];

int main() {
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB") {
        puts("No");
    }else {
        puts("Yes");
    }
}


