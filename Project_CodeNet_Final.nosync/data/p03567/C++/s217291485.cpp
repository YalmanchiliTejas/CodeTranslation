#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 1000010;
const int MX = 123456;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const ull BS1 = 10000019ULL;
const int INF = (1 << 30);

template < class T > inline void fastScan(T &x){
    register char c = getchar();
    int neg = 0; x = 0;
    for(   ; (c < 48 || c > 57) && (c != '-'); c = getchar());
    if(c == '-') { neg = 1; c = getchar(); }
    for(   ; c > 47 && c < 58; c = getchar()){
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(neg) x = -x;
}

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

char s[10];

int main(){
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 1; i < len; i++){
        if(s[i - 1] == 'A' && s[i] == 'C'){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
