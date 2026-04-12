#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<unordered_map>
#include<array>
#include<map>
#include<iomanip>
using namespace std;
typedef long long int llint;
typedef long double lldo;
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
#define dme cout<<-1<<endl;return 0
//ios::sync_with_stdio(false);
//<< setprecision(5)
const int mod=1e9+7;
const llint big=1e15+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
int main(void){
	string str;cin>>str;
	if(str[0]=='A'&&str[1]=='C'){cout<<"Yes"<<endl;}
	else if(str.size()>2&&str[1]=='A'&&str[2]=='C'){cout<<"Yes"<<endl;}
	else if(str.size()>3&&str[2]=='A'&&str[3]=='C'){cout<<"Yes"<<endl;}
	else if(str.size()>4&&str[3]=='A'&&str[4]=='C'){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
}