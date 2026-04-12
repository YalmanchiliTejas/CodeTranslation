#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef pair<int,int> P;
typedef long long ll;

int main(void){

	string x;
	ll a;
	cin >> x >> a;

	int n=x.size();
	ll lr=x[0]-'0';
	int i;
	for(i=1;i<n;i+=2){
		if(x[i]=='+') lr+=x[i+1]-'0';
		if(x[i]=='*') lr*=x[i+1]-'0';
	}

	ll mf=0,q=1;
	if(n==1){
		if(a==x[0]-'0') cout << "U" << endl;
		else cout << "I" << endl;
		return 0;
	}
	for(i=0;i<n;i+=2){
		if(i!=0 && i!=n-1) if(x[i-1]=='*' && x[i+1]=='*') q*=x[i]-'0';
		if((i==0 && x[i+1]=='*') || (x[i-1]=='+' && x[i+1]=='*')) q*=x[i]-'0';
		if((i==n-1 && x[i-1]=='*') || (x[i-1]=='*' && x[i+1]=='+')){
			q*=x[i]-'0'; mf+=q; q=1;
		}

		if(i!=0 && i!=n-1) if(x[i-1]=='+' && x[i+1]=='+') mf+=x[i]-'0';
		if(i==0) if(x[i+1]=='+') mf+=x[i]-'0';
		if(i==n-1) if(x[i-1]=='+') mf+=x[i]-'0';
	}



	if(lr==mf && lr==a) cout << "U" << endl;
	else if(mf==a) cout << "M" << endl;
	else if(lr==a) cout << "L" << endl;
	else cout << "I" << endl;

	return 0;
}