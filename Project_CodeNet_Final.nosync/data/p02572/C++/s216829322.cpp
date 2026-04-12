#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
using namespace std;
#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;
 
const int inf = (int)1e9; 
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}
 

 
int main(void){
    int n;
    cin>>n;
    vector<ll>a(n),s(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    s[0]=0;
    for(int i=0;i<n;i++){
        s[i+1] = (s[i]+a[i])%N;
    }
    ll ans = 0;
    for(int i=0;i<n-1;i++){
        ll t = (a[i]*(s[n]-s[i+1]))%N;
        ans = (ans+t)%N;
    }
    cout<<(ans+N)%N<<endl;
	return 0;
}