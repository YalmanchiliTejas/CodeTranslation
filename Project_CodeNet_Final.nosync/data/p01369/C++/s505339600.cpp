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
  string right = "qwertasdfgzxcvb";
  string left = "yuiophjklnm";

  while(1){

	string str;
	cin >> str;

	if(str[0]=='#')
	  break;

	int size = str.size();
	int r = right.size();
	int x[500]={0};
	int ans=0;

	REP(i,size){
	  REP(j,r){
		if(str[i]==right[j]){
		  x[i]=1;
		}
	  }
	  if(i!=0&&x[i]!=x[i-1])
		ans++;
	}
	cout << ans<<endl;
  }
}