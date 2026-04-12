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

int mylog10(int x){
	if(x==0) return 0;
	else return (int)log10(x);
}

string gettopnum(string str){
	string rst = "";
	REP(i,str.size()){
		if(str[i]=='*'||str[i]=='+') break;
		else rst += str[i];
	}
	return rst;
}

string strerase(string instr,int num){
	string rst = "";
	for(int i=num;i<instr.size();i++){
		rst += instr[i];
	}
	return rst;
}
ll int calc1(string str){//multiplication-first
	stack<ll int> st;
	string rststr = gettopnum(str);
	if(rststr!="") st.push((ll int)stoi(rststr));
	if(rststr!="") str = strerase(str,mylog10((double)stoi(rststr))+1);
	while(str.size()!=0){
		//cout << str << endl;
		if(str[0]=='*'){
			str = strerase(str,1);
			ll int tmp = stoi(gettopnum(str));
			str = strerase(str,(int)mylog10((double)tmp)+1);
			ll int tmp2 = st.top();
			st.pop();
			st.push(tmp*tmp2);
		}else if(str[0]=='+'){
			str = strerase(str,1);
			ll int tmp = stoi(gettopnum(str));
			st.push(tmp);
			str = strerase(str,(int)mylog10((double)tmp)+1);
		}
	}
	ll int rst = 0;
	while(!st.empty()){
		rst += st.top();
		st.pop();
	}
	return rst;
}

ll int calc2(string str){////multiplication-first2
	//cout << str << endl;
	string rststr = gettopnum(str);
	ll int rst;
	if(rststr!="") rst = stoi(rststr);
	if(rststr!="") str = strerase(str,(int)mylog10((double)rst)+1);
	if(str.size()==0) return rst;
	else if(str[0]=='*') {
		str = strerase(str,1);
		return rst*calc2(str);
	}else if(str[0]=='+'){
		str = strerase(str,1);
		return rst+calc2(str);
	}
	//dummy
	return -1;
}

ll int calc3(string str){//leftto-right
	string rststr = gettopnum(str);
	if(rststr!="") str = strerase(str,(int)mylog10((double)stoi(rststr))+1);
	ll int rst = stoi(rststr);
	while(str.size()!=0){
		//cout << str << endl;
		if(str[0]=='*'){
			str = strerase(str,1);
			ll int tmp = stoi(gettopnum(str));
			rst *= tmp;
			str = strerase(str,(int)mylog10((double)tmp)+1);
		}else if(str[0]=='+'){
			str = strerase(str,1);
			ll int tmp = stoi(gettopnum(str));
			rst += tmp;
			str = strerase(str,(int)mylog10((double)tmp)+1);
		}
	}
	return rst;
}

int main(){
	string str;
	cin >> str;
	ll int ans;
	cin >> ans;
	ll int rst1 = calc1(str);//calc2　is bug
	ll int rst2 = calc3(str);
	//cout << rst1 << " " << rst2 << endl;
	if(rst1==ans){
		if(rst2==ans) cout << 'U' << endl;
		else cout << 'M' << endl;
	}else{
		if(rst2==ans) cout << 'L' << endl;
		else cout << 'I' << endl;
	}
	return 0;
}