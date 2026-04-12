#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 3005;
ll dp[MAX_N][MAX_N],arr[MAX_N];
/*
题意 给你一个序列一个人先拿 另一个人后拿 只能从序列的开头或者结尾拿一个元素
先拿的分数是 X 后拿的人分数是 Y 他们都想要自己的分数差最大 也就是第一个人是 X - Y最大
第二个人是 Y - X最多    我们发现对这类dp 只有dp[l][r] 代表区间 l 到 区间 r 的最大 X - Y
只有当L = R的时候 才能确定取的是arr[l],arr[R] 
如果不等于 就从上个状态 arr[L] - dp[L+1][R] , arr[R] - dp[L][R-1]
推过来 为什么要减 因为上个人的值正好是下个人的负值
因为是L + 1 所以我们 L 从n 到 1
因为是R - 1 所以我们R 从 L 到 n
*/
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) scanf("%d",&arr[i]);
    
    for(int L = n;L>=1;--L)
    {
        for(int R = L;R<=n;++R)
        {
        	//dp[L][R]为区间L到R的最大x-y; 
        	
            dp[L][R] = max(arr[L]-dp[L+1][R],arr[R]-dp[L][R-1]);
            
            //区间L->R为 区间尾-区间L+1->R   和     区间头-区间L->R-1    的最大值；
			//反向算法 
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}
