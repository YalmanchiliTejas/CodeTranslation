#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#define int long long
const int inf=1145141919;
const int mod=1000000007;
using namespace std;
template<class T>void debug(T *a,int l,int r,const char *name){
	for(int i=l;i<r;i++)
		cout<<name<<"["<<i<<"]="<<a[i]<<endl;
}
signed main(){
	int i,j;
	string s;
	cin>>s;
	for(i=0;i+1<s.size();i++)
		if(s[i]=='A'&&s[i+1]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"No"<<endl;
}