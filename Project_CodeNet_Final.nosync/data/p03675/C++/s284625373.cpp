#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<chrono>
#include<random>
#include<unordered_set>
using namespace std;
typedef long long int llint;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
const int mod=1000000007;
const int big=1e9-10;
const llint red=0xE869120;
const llint pro=1002001;
const long double pai=3.141592653589793238462643383279;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}

int main(void){
	int n,i;cin>>n;
	deque<int>a(n);
	deque<int>b;
	for(i=0;i<n;i++){cin>>a[i];}
	for(i=0;i<n;i++){
		if((n-i)%2==1){b.push_front(a[i]);}
		else{b.pub(a[i]);}
	}
	for(i=0;i<n;i++){
		cout<<b[i]<<" ";
	}cout<<endl;
	return 0;
}