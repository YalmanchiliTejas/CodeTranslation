#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"
 
#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
typedef long long ll;
using namespace std;

int n;
ll cnt,a[50],p;
bool b;

int main(){
	cin>>n;
	rep(n)
		cin>>a[i];
	cnt=p=0;
	b=true;
	while(b){
		b=false;
		rep(n){
			if((a[i]-p)/n){
				b=true;
				cnt+=(a[i]-p)/n;
				a[i]-=(a[i]-p)/n*(n+1);
				p=-cnt;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
