#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
int m;

template<typename T>
inline void read(T &x){
    x = 0; char ch = getchar(); int f = 1;
    for(;ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
    x *= f;
}

int main(){
    read(m);
    if(m >= 30) printf("Yes\n");
    else printf("No\n");
    return 0;
}
/*

*/