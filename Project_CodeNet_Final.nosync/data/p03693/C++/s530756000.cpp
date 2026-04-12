#include<bits/stdc++.h>
#define rep(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define rep1(i,n)for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=(int)(n)-1;0<=i;i--)
#define rrep1(i,n) for(int i=(int)(n);1<=i;i--)

#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(obj) (obj).begin(),(obj).end() 

#define pcount __builtin_popcount
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())

#define dump(x)  cerr << #x << " = " << (x) << endl;

template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

#define endl "\n"

typedef long long lint;

using namespace std;
int main(){
	char c[3];
	rep(i,3)cin>>c[i];
	cout<<(stoi(c)%4==0?"YES":"NO")<<endl;
}