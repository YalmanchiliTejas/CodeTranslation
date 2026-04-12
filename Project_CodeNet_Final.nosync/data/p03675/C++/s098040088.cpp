#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef pair<LL,LL>PII;

/*
题意：
给你n个数，求区间有多少对除数和被除数的对数

思路：
线段树 区间和/ 树状数组 前缀和
2e5的数的除数最多才81个
对于一个数的贡献，我最好是区间的贡献，也就是1-n的贡献。
*/

const int N=2e5+10;
int a[N],n;
vector<int>ans;

int main(){
    ans.clear();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n == 1)
    {
        printf("%d\n",a[1]);
        return 0;
    }
    if(n%2 == 0){
        int t = n;
        while(t>1){
            ans.push_back(a[t]);
            t -= 2;
        }
        t = 1;
        while(t<n)
        {
            ans.push_back(a[t]);
            t += 2;
        }
    }
    else if(n%2 == 1){
        int t = n;
        while(t>=1){
            ans.push_back(a[t]);
            t -= 2;
        }
        t = 2;
        while(t<n)
        {
            ans.push_back(a[t]);
            t += 2;
        }
    }
    int sz = ans.size();
    for(int i=0;i<sz;i++){
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}

