/*	                           
							 * * 
						   *     * 
						 *	       * 
					   *	         * 
                     *     _ooOoo_     * 
                   *      o8888888o      * 
                 *        88" . "88        * 
                *         (| -_- |)         * 
               *       *  0\  =  /0  *       * 
               *       *__0/`---'\0__*       * 
               *     .'  \\|     |//  `.     * 
                *   /  \\|||  :  |||//  \   * 
                 * /  _||||| -:- |||||-  \ * 
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
              ."" '<  `.___\_<|>_/___.'  >'"".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `-.   \_ __\ /__ _/   .-` /  /
        ======`-.____`-.___\_____/___.-`____.-'======
                           `=---='
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                   佛祖保佑       永无BUG
                        author：Richie 
*/

#include<stdio.h>
#include<string.h>	
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a);i <= (b); i++)
#define ROF(i, a, b) for(int i = (a);i >= (b); i--)
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q)) 
#define LOCAL
#define N 500001
#define mod (unsigned long long)(1e9+7)

int cmp (const void *a, const void *b);//升序排列 
void print_array (int *a, int n);
void read_array (int *a, int n);
void init (void);
double lnchoose (int n, int m);
double choose (int n, int m);
ll fast (ll x);//逆元 费马小定理/欧拉定理 适用范围：一般在mod是个素数的时候用
ll exgcd (ll a, ll b, ll *x, ll *y);
ll getInv (int a);//求a在mod下的逆元，不存在逆元返回-1 
ll gcd (ll a, ll b);



int main(){
	int n;
	ll a[200005];
	scanf("%d",&n);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);	
	}
	ll front=0;
	ll last=0;
	for(int i=1;i<n;i++){
		front=a[i];
		last+=a[i-1];
		last=last%1000000007;
		sum+=(front*last);
		sum=sum%1000000007;
	}
	printf("%lld",sum);
	return 0;
}







ll gcd (ll a, ll b)
{
	int t;
	while (b != 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

ll fast (ll x)
{									
	int y = mod - 2;
	ll res = 1;
	while (y){
		if (y & 1)res = res * x % mod;
		x = x * x % mod; 
		y >>= 1;
	}
	return res;
}

ll exgcd(ll a,ll b,ll *x,ll *y)					//扩展欧几里得算法 
{
    if(b==0)
    {
        *x = 1,*y = 0;
        return a;
    }
    ll ret = exgcd (b, a % b, y, x);
    *y -= a / b * (*x);
    return ret;
}
ll getInv (int a)								
{
    ll x, y;
    ll d = exgcd (a, mod, &x, &y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}

void init (void)
{
	#ifdef LOCAL
		freopen ("data.txt", "r", stdin);
		freopen ("out.txt", "w", stdout);
	#endif
}

int cmp (const void *a, const void *b)
{
	return *(int*)a - *(int*)b;					
} 

void print_array (int *a, int n)
{
	FOR(i,1,n){
		if (i != n) printf("%d ",a[i]);
		else printf("%d",a[i]);
	}
	printf("\n");
} 

void read_array (int *a, int n)
{
	FOR(i, 1, n)scanf("%d",&a[i]);
}

double lnchoose (int n, int m)
{
	if (m > n){
		return 0;
	}
    if (m < n / 2.0)
    {
        m = n - m;
    }
    double s1 = 0;
    for (int i = m + 1; i <= n; i++)
    {
        s1 += log((double)i);
    }
    double s2 = 0;
    int ub = n - m;
    for (int i = 2; i<= ub; i++)
    {
        s2 += log((double)i);
    }
    return s1-s2;
}
double choose(int n, int m)
{
	if (m > n)
    {
		return 0;
	}
    return exp(lnchoose(n, m));
}

