#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
const ll mod=1e9+7;


int S,T;
string s,t;

vi f(){
	int I=0;
	vi a;
	for(int i=0;i<S;i++) if(I<T&&s[i]==t[I]){
		a.push_back(i);
		I++;
	}
	for(int i=a.size();i<T;i++) a.push_back(S);
	return a;
}

int main(){
	cin>>s>>t;
	S=s.size();
	T=t.size();
	vi a=f();
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	vi b=f();
	bool flag=1;
	for(int i=0;i<T;i++) if(a[i]+b[T-i-1]!=S-1) flag=0;
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}