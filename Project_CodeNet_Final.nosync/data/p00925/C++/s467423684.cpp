#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
#define all(a) a.begin(),a.end()

int main(){
	int l=0,n=0,p;
	vector<int> a(1);
	string s;
	cin>>s>>p;
	
	l=a[0]= s[0]-'0';
	for(int i=2; i<s.size() ;i+=2){
		int t=s[i]-'0';
		if(s[i-1]=='*'){
			l*=t;
			a.back()*=t;
		}else{
			l+=t;
			a.push_back(t);
		}
	}
	n=accumulate(all(a),0);
	cout<<"ILMU"[(l==p?1:0) + (n==p?2:0)]<<endl;
	return 0;
}

