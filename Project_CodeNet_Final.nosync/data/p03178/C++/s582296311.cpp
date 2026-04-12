#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include <set>
#include <limits.h>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

long long pow(long long n, long long p,long long k) {//n^k(mod p)
	if (k != 0) {
		if (p % 2==0) {
			long long x = pow(n, p, k / 2);
			return (long long)x*x%p;
		}
		else {
			long long x = pow(n, p, k - 1);
			return (long long)x*n%p;
		}
	}
	return 1;
}

long long rev(long long n, long long p) {//nの逆元
	return pow(n, p ,p - 2);
}

long long bino(long long n, long long m, long long p) {//nCm(mod p)
	long long me = 1;
	long long ans = 1;
	for (int i = 0;i < n + m;i++) {
		me = (long long)(i + 1) * ans % p;
		if (i == m - 1) {
			ans =(long long) rev(me,p) * ans%p;
		}
		if (i == m - n - 1) {
			ans = (long long)(rev(me, p))*ans%p;
		}
	}
	ans = (long long)(ans*me%p);
	return ans;
}

struct modint{
    long long num;
    long long p;
    modint () {
        num=0;
        p=1000000007;
    }
    modint(int x){
        p=1000000007;
        num=(long long) x%p;
    }
    modint (long long x){
        p = 1000000007;
        num = x%p;
    }
    modint operator+(const modint &other){
        modint ret;
        ret.p=p;
        ret.num=(num+other.num)%p;
        return ret;
    }
	modint operator+(const long long &other){
        modint ret;
        ret.p=p;
        ret.num=(num+(other%p))%p;
        return ret;
    }
    modint operator-(const modint &other){
        modint ret;
        ret.p=p;
        ret.num=(num-other.num+p)%p;
        return ret;
    }
    modint operator-(const long long &other){
        modint ret;
        ret.p=p;
        ret.num=(num-(other%p)+p)%p;
        return ret;
    }
    modint operator*(const modint &other){
        modint ret;
        ret.p=p;
        ret.num=(num*other.num)%p;
        return ret; 
    }
    modint operator*(const long long &other){
        modint ret;
        ret.p=p;
        ret.num=(num*(other%p))%p;
        return ret; 
    }
    modint operator/(const modint &other){
        modint ret;
        ret.p=p;
        ret.num=(num*rev(other.num,p))%p;
		return ret;
    }
    modint operator/(const long long &other){
        modint ret;
        ret.p=p;
        ret.num=(num*rev(other%p,p))%p;
		return ret;
    }
};

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n=s.size();
    vector<vector<modint>> dp(n+1,vector<modint>(k));
    dp[n][0]=dp[n][0]+1;
    int no=0;
    for (int i=n-1;i>-1;i--){
        dp[i+1][no%k]=dp[i+1][no%k]-1;
        int x=s[n-i-1]-'0';
        rip(j,k,0){
            rip(l,10,0){
                dp[i][(j+l)%k]=dp[i+1][j]+dp[i][(j+l)%k];
            }
        }
        rip(j,x+1,0){
            dp[i][(j+no)%k]=dp[i][(j+no)%k]+1;
        }
        no+=x;
    }
    dp[0][0]=dp[0][0]-1;
    cout << dp[0][0].num << endl;
}