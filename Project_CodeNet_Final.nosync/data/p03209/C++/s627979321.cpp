#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define isNum(a) (a>='0'&&a<='9')
#define SP putchar (' ')
#define EL putchar ('\n')
#define inf 2147483647
#define N 55
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
typedef unsigned long long int ll;
template<class T1>inline void read(T1&);
template<class T1>inline void write(T1);
ll work(int, ll);
ll num[N];
ll ful[N];
int main () {
    num[0]=1;
    ful[0]=1;
    for (int i=1; i<=50; ++i) {
        num[i]=3+(num[i-1]<<1);
        ful[i]=1+(ful[i-1]<<1);
    }
    int n;
    ll x;
    read(n);
    read(x);
    write(work(n, x));
    EL;
    return 0;
}
template<class T1>void read(T1 &r_e_a_d) {
    T1 k=0;
    char ch=getchar();
    int flag=1;
    while (!isNum(ch)) {
        if (ch=='-') {
            flag=-1;
        }
        ch=getchar();
    }
    while (isNum(ch)) {
        k=(k<<1)+(k<<3)+ch-'0';
        ch=getchar();
    }
    r_e_a_d = flag*k;
}
template<class T1>void write(T1 w_r_i_t_e) {
    if (w_r_i_t_e<0) {
        putchar('-');
        write(-w_r_i_t_e);
    }else {
        if (w_r_i_t_e<10) {
            putchar(w_r_i_t_e+'0');
        }else {
            write(w_r_i_t_e/10);
            putchar((w_r_i_t_e%10)+'0');
        }
    }
}
ll work(int n, ll x) {
    if (n==0) {
        return x;
    }
    if (x<=0) {
        return 0;
    }
    --x;
    ll ans=0;
    if (x<=num[n-1]) {
        ans+=work(n-1, x);
    }else {
        ans+=ful[n-1]+1;
        x-=num[n-1]+1;
        ans+=work(n-1, min(x, num[n-1]));
    }
    return ans;
}
