/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	是否可以简化问题：
	抓住数据范围哪里小
	dfs or bfs
	是否可以化具体为抽象
	字符串问题是否可以用数学模拟递归过程（取c[i]或不取来算结果）
	二分？左闭右开？
	long long？
	逆向思维？
	dp？
	贪心？
	树的直径:随便找一点再走到它最远的点A，再从A最远的点走到最远B的点。AB就是树的直径
	匹配括号 左减右>=0
	字符串赋值字符加单引号
	double> printf("%lf")输出小数点6位，%.16lf输出后十六位
	多组数据清空？
	dp优化用g？
	线段树：大小为n的8倍
	线段树：左闭右开！
	线段树：find： if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	线段树：满二叉树 
	循环跳出条件 
	代数设出每个值寻找关系？
	优先队列：priority_queue<类型> q;   
	priority_queue<类,vector<类>, less<类> > pq1; 　　　 // 使用递减	
	priority_queue<类，vector<类>, greater<类> > pq2; 　　// 使用递增
	判断括号，判断是否长度为偶数
	1<<ceil(log2(double(n)))
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[3005][3005];
int n;
LL a[3005];
int main(){
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	rb(i,1,n)scanf("%lld",&a[i]);
	rl(i,n,1){
		rb(j,i,n){
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	printf("%lld",dp[1][n]);
	return 0;
}
