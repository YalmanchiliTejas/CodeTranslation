#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, N = 2 * 1e5 + 10;
	ll n;
  	ll a[N], q[N];
	ll sum = 0;
int main(){
    q[0] = 0;
    a[0] = 0;
  	cin >> n;//输入n
  	for(int i = 1; i <= n; i ++){
     	cin >> a[i] ;//输入所有的数
      	a[i] %= mod;//然后先mod,原数组;
      	q[i] = (q[i - 1] +a[i]) % mod;//前缀和数组
      	sum = (sum + (a[i] * q[i - 1] % mod)) % mod ;
        
    }
  cout << sum;
  return 0;
}