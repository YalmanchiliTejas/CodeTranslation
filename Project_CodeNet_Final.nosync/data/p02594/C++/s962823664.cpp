#include <bits/stdc++.h>
using namespace std;
//useful 
#define rep(i,n) for(int i = 0; i < (n); i++)
int long long gcd(int long long a, int long long b){
    return b?gcd(b,a%b):a;
} //最大公約数
int long long lcm(int long long a, int long long b){
    return a/gcd(a,b)*b;
} //最小公倍数
int long long GetDigit(int long long num){
    int long long digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
} //桁数
int long long GetDigitN(int long long num, int long long N){
    int long long digit=0;
    while(num!=0){
        num /= N;
        digit++;
    }
    return digit;
} //十進数でnumの際のN進数における桁数
int long long divisorcount(int long long n){
	int long long ans = 1;
	vector<int> x(n + 1);
	int long long num = n; // 素因数分解する変数num 
	for (int long long i = 2; i <= n; i++) {
		while (num%i == 0) { // 素数で割り切れなくなるまで割っていく
			x.at(i)++; //割った個数を配列に足す
			num /= i;
		}
	}
	for (int i = 2; i <= n; i++){	
		ans *= x.at(i) + 1; //それぞれを+1して掛けていく
	}
    return ans;
} //約数カウント

int main(){
    int A;
    cin >> A;
    if(A >= 30){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}