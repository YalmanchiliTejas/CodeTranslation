#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

struct Dice{
	int face[6]; // top,bottom,left,right,front,back
	void Rotate(int a,int b,int c,int d){
		int temp=face[a];
		face[a]=face[b];
		face[b]=face[c];
		face[c]=face[d];
		face[d]=temp;
	}
	void TurnF(int n){rep(i,n)Rotate(0,2,1,3);}
	void TurnR(int n){rep(i,n)Rotate(0,4,1,5);}
	void TurnU(int n){rep(i,n)Rotate(4,3,5,2);}
	void TurnF(){TurnF(1);}
	void TurnR(){TurnR(1);}
	void TurnU(){TurnU(1);}
};

int main()
{
	for(int n;cin>>n,n;){
		Dice d={1,6,4,3,2,5};
		int res=1;
		rep(i,n){
			string s;
			cin>>s;
			if(s=="North")
				d.TurnR();
			if(s=="East")
				d.TurnF();
			if(s=="South")
				d.TurnR(3);
			if(s=="West")
				d.TurnF(3);
			if(s=="Right")
				d.TurnU();
			if(s=="Left")
				d.TurnU(3);
			res+=d.face[0];
		}
		cout<<res<<endl;
	}
	
	return 0;
}