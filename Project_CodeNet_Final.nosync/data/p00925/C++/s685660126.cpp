#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;
string s;
long long a;
int f;
char* ans = "ILMU";
int main()
{
	cin>>s>>a;
	stack<long long> st;
	long long v=0;
	for (int i = 0; i < s.size(); i++)
	{
		if(i&1){
			if(s[i]=='+')
				v+=s[++i]-'0';
			else if(s[i]=='*')
				v*=s[++i]-'0';
			else;
		}
		else v=s[i]-'0';
	}
	if(v==a)f+=1;
	v=0;
	for (int i = 0; i < s.size(); i++){
		if(i&1){
			if(s[i]=='*'){
				long long top = st.top();st.pop();
				top*=s[++i]-'0';
				st.push(top);
			}
		}
		else st.push(s[i]-'0');
	}
	while(!st.empty()){
		v+=st.top();
		st.pop();
	}
	if(v==a)f+=2;
	cout<<ans[f]<<endl;
	return 0;
}
