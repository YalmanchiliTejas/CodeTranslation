#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j); i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
typedef long long LL;
int get_int(){int x;scanf("%d",&x);return x;}
int get_ll(){LL x;scanf("%lld",&x);return x;}

void tests(){
    ;
}

int main()
{
    int N = get_int();
    int res = 0;
    int h = -1;
    _for(i,0,N){
        int num = get_int();
        if(num >= h) res++;
        h = max(num,h);
    }
    cout << res << endl;
    return 0;
}
