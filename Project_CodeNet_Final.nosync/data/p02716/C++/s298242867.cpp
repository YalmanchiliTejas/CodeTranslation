#include <iostream>//数据输入输出流
#include <cstring>//字符串操作函数
#include <cstdio>//C的输入输出
#include <cstdlib>//定义杂项函数及内存分配函数
#include <cmath>//C中的数学函数
#include <string>//c++中的string类 他不能用strcpy等c函数去操作
#include <vector>//STL vetor
#include <list>//STL list
#include <map>// STL map
#include <queue>// STL queue
#include <stack>//sTL stack
#include <bitset>//bitset可按位定义串
//比如：bitset <1000> all;定义一个1000位的串
#include <algorithm>//STL各种算法 比如 swap sort merge max min 比较
#include <numeric>//常用数字操作 一般和algorithm搭配使用
#include <functional>//STL定义运算函数（代替运算符）
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
#define LOCAL
#define zeros(a,n) memset(a,0,(n)*sizeof(a[0]))
const int modn = 1e9+7;
int mod(int x) { return x<0?x+modn:x<modn?x:x-modn; }
//inv [ i ] = (modn - modn/i)*inv[ modn%i ] %modn;
const int N = 200005;
int n;
int a[N];
LL sum[N][2];
LL f[N];
LL dfs1(int p){
    if(p > n) return 0;
    if(f[p]) return f[p];
    return f[p] = max(a[p] + dfs1(p + 2), sum[p+1][(p+1)%2]);
}
LL dfs2(int p){
    if(p >= n) return 0;
    if(f[p]) return f[p];
    return f[p] = max(a[p] + dfs2(p + 2), dfs1(p+1));
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i = n; i>=1; --i){
        sum[i][0] = sum[i+1][0];
        sum[i][1] = sum[i+1][1];
        sum[i][i%2] = sum[i+1][i%2] + a[i];
    }
    if(n % 2 == 0){
        cout << dfs1(1) << endl;
    }else{
        cout << dfs2(1) << endl;
    }
    return 0;
}

