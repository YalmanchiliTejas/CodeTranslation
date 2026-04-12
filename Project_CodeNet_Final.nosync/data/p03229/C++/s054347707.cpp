
#include <bits/stdc++.h>
#include <cstdlib>  // abs() for integer 絶対値求めやつ
#include <cmath>    // abs() for float, and fabs()
#include <algorithm>
#include <vector>
#include <string>
#include<iomanip>//浮動小数点数を出力する制度の指定
//使い方　数値をnumとして　cout<<setprecision(n)<<num ;nは桁数
#define rep(i,n) for(int i = 0; i < (n);i++)
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
using namespace std;
using ll =long long;
#define INF 2000000000
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
/*覚えてないことメaモ
  数値型から文字列に変換　to_string(number);これは簡単
  文字列から数値型に変換　stoi(number)
  文字列からllに変換　stoll(number)*/

//ここから書き始める

int main(){
	ll n; cin >> n; 
	vector<ll> a(n);
	rep(i,n) cin >>a[i];
	SORT(a);
	vector<ll> b(n);//かける数
	vector<ll> c(n);
	rep(i,n){
		if(i == 0){
			c[i] = 1;
		}
		else if(i == n-1 ){
			if(n % 2 ==0){
				c[i] = -1;
			}
			else{
				c[i] = 1;
			}
		}
		else if(i%2 == 1){ 
			c[i] = -2;
		}
		else c[i] =2;
	}
	SORT(c);
//	rep(i,n){
//		cout<<c[i]<<" ";
//	}
	if(n % 2 == 0){
		rep(i,n){
			if(i==0) b[i] = -1;
			else if(i == n - 1) b[i] = 1;
			else{
				if(i%2 ==0) {
					b[i] =-2;
				}
				else{
					b[i] = 2;
				}
			}
		}
	}

	else if( n % 2 == 1){
		rep(i,n){
			if(i == 0 || i == n-1 ){
				b[i] = -1;
			}
			else if ( i%2 == 0 ){
				b[i] =-2;
			}
			else if( i % 2 == 1){
				b[i] = 2;
			}
		}
	}
	SORT(b);
//	rep(i,n){
//		cout<<b[i]<<" ";
//	}
	ll ans = 0 ;
	ll ans1 = 0;
	rep(i,n){
		ans += a[i] * b[i];
		ans1+= a[i] * c[i];
	}
	chmax(ans,ans1);
	cout<<ans<<endl;


}
