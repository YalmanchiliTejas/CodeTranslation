#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ins insert
#define pii pair<int,int>
#define fs first
#define sc second
#define mpr make_pair
#define iter iterator
#define all(X) X.begin(),X.end()
#define sau(X) sort(all(X)),X.resize(unique(all(X))-X.begin())
#define exist(X,ele) binary_search(all(X),ele)

template<typename T1,typename T2>
ostream& operator << (ostream& out,const pair<T1,T2>& X)
{
	out<<"{"<<X.fs<<","<<X.sc<<"}";
	return out;
}

template<typename T>
ostream& operator << (ostream& out,const vector<T>& X)
{
	for(auto i:X) out<<i<<" ";
	return out;
}

inline void cmin(int& x,int y)
{
	x=min(x,y);
}

inline void cmax(int& x,int y)
{
	x=max(x,y);
}

const int inf=5000000000000000ll;

main()
{
	ios::sync_with_stdio(false);
	
	int x,y; cin>>x>>y;
	if(x==y) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}




















