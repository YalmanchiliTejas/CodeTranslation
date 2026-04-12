#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;
 
#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

			 
int main(){
  while(1){
	int a,b,c,x,n;
	int s[200];
	cin>>n>>a>>b>>c>>x;
	if(a==0&&b==0&&c==0&&n==0&&x==0)
	  break;
	REP(i,n){
	  cin>>s[i];
	}

	//cout << s[0] << endl;//

	int ransu = x;
	int count = 0;
	int m=0;
	while(1){
	  if(count > 10000){
		count = -1;
		break;
	  }
	  if(ransu == s[m]){
		m++;
	  }
	  if(m==n){
		break;
	  }
	  ransu = (a*ransu+b)%c;
	  count++;
	}  
	cout << count << endl;
  }

}