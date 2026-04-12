#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <string>
#include <utility>

#define repd(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

int inputValue();
void inputArray(int*,int);
void inputVector(vector<int>*,int);
template <typename T>
void output(T,int);
int gcd(int a,int b);

int main(){
	//source
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	ll a_double,b_double,AandB;
	a_double=a*2;
	b_double=b*2;
	AandB=a+b;
	ll ans=0;
	if(c*2<a+b){
		int number=min(x,y);
		ans+=number*2*c;
		x-=number;
		y-=number;
	}else{
		int number=min(x,y);
		ans+=number*AandB;
		x-=number;
		y-=number;
	}

	if(x==0){
		ans+=min(y*b,y*c*2);
	}else{
		ans+=min(x*a,x*c*2);
	}

	cout << ans << endl;
	return 0;
}

int inputValue(){
	int a;
	cin >> a;
	return a;
}

void inputArray(int *p,int a){
	rep(i,a){
		cin >> p[i];
	}
}

void inputVector(vector<int> *p,int a){
	rep(i,a){
		int input;
		cin >> input;
		p -> push_back(input);
	}
}

template<typename T>
void output(T a,int precision){
	if(precision > 0){
		cout << setprecision(precision) << a << "\n";
	}else{
		cout << a << "\n";
	}
}

int gcd(int a,int b){
	if(b>a){
		int temp=a;
		a=b;
		b=temp;
	}
	if(b==0){
		return a;
	}
	return (b,b%a);
}
