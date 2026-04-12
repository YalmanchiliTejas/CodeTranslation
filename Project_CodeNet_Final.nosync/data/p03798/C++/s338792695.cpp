#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 100010;

inline int in() {int x; scanf("%d",&x); return x;}
inline ll lin() {ll x; scanf("%lld",&x); return x;}

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

int n;
char s[N];

int dp[N][2][3][3][3];

int go(int now, int what, int prev, int first, int last){
    if(now == n){
        return (what == first);
    }

    if(now == n - 1){
        if(what != last) return false;
    }

    if(dp[now][what][prev][first][last] != -1){
        return dp[now][what][prev][first][last];
    }

    bool ret = false;

    if(now == 0){
        if(what == 0){
            if(s[0] == 'o'){
                ret |= go(now + 1, 0, what, what, 0);
                ret |= go(now + 1, 1, what, what, 1);
            }else {
                ret |= go(now + 1, 0, what, what, 1);
                ret |= go(now + 1, 1, what, what, 0);
            }
        }else {
            if(s[0] == 'x'){
                ret |= go(now + 1, 0, what, what, 0);
                ret |= go(now + 1, 1, what, what, 1);
            }else {
                ret |= go(now + 1, 0, what, what, 1);
                ret |= go(now + 1, 1, what, what, 0);
            }
        }
    }else {
        if(what == 0){
            if(s[now] == 'o'){
                ret |= go(now + 1, prev, what, first, last);
            }else {
                ret |= go(now + 1, !prev, what, first, last);
            }
        }else {
            if(s[now] == 'x'){
                ret |= go(now + 1, prev, what, first, last);
            }else {
                ret |= go(now + 1, !prev, what, first, last);
            }
        }
    }

    return dp[now][what][prev][first][last] = ret;
}

void print(int now, int what, int prev, int first, int last){
    if(now >= n) return ;
    if(now == 0){
        if(what == 0){
            if(s[0] == 'o'){
                if(go(now + 1, 0, what, what, 0)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 0, what, what, 0); }
                else if(go(now + 1, 1, what, what, 1)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 1, what, what, 1); }
            }else {
                if(go(now + 1, 0, what, what, 1)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 0, what, what, 1);}
                else if(go(now + 1, 1, what, what, 0)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 1, what, what, 0);}
            }
        }else {
            if(s[0] == 'x'){
                if(go(now + 1, 0, what, what, 0)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 0, what, what, 0);}
                else if(go(now + 1, 1, what, what, 1)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 1, what, what, 1);}
            }else {
                if(go(now + 1, 0, what, what, 1)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 0, what, what, 1);}
                else if(go(now + 1, 1, what, what, 0)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, 1, what, what, 0);}
            }
        }
    }else {
        if(what == 0){
            if(s[now] == 'o'){
                if(go(now + 1, prev, what, first, last)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, prev, what, first, last);}
            }else {
                if(go(now + 1, !prev, what, first, last)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, !prev, what, first, last);}
            }
        }else {
            if(s[now] == 'x'){
                if(go(now + 1, prev, what, first, last)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, prev, what, first, last);}
            }else {
                if(go(now + 1, !prev, what, first, last)){ printf("%c", what == 0 ? 'S' : 'W'); print(now + 1, !prev, what, first, last);}
            }
        }
    }
}

int main(){
    n = in();
    scanf("%s", s);

    memset(dp, -1, sizeof dp);

    int flag = go(0, 0, 2, 2, 2);

    if(flag == 1){
        print(0, 0, 2, 2, 2);
        return 0;
    }

    memset(dp, -1, sizeof dp);

    flag = go(0, 1, 2, 2, 2);

    if(flag == 1){
        print(0, 1, 2, 2, 2);
        return 0;
    }


    if(!flag) printf("-1\n");

}
