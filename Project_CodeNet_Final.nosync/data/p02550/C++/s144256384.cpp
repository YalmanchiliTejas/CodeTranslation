//https://atcoder.jp/contests/abc179/tasks/abc179_e
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int MAXN=1e5+4;
const int MAXM=1e5+4;
int idx[MAXM];//和位置索引
ULL sum[MAXN];//和

int main() {
    ULL  n,x,m;
    cin>>n>>x>>m;

    //打表
    ULL l, r;
    for (ULL i=1, num=x; ; num=num*num%m, i++) {
        if (!idx[num]) {
            //没有计算过，标注已经计算
            idx[num]=i;
        } else {
            //数据存在
            l=idx[num];
            r=i-1;
            break;
        }
        //更新数据表
        sum[i]=sum[i-1]+num;
    }

    ULL len=r-l+1;
    ULL ans=0;
    ans+=sum[min(n, l-1)];
    
    n=max(0ULL, n-l+1);
    if (n) {
        ans+=(sum[r]-sum[l-1])*(n/len)+(sum[n%len+l-1]-sum[l-1]);
    }

    cout<<ans<<"\n";

    return 0;
}