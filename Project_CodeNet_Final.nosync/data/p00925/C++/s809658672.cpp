#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)


class C{
	public:
	vector<int> num;
	vector<char> calc;
	
	bool emp(){
		bool nu = false;
		rep(i,calc.size())if(calc[i]=='*')nu=true;
		return !nu;
	}
	
	void docalc(int i)
	{
		if(calc[i]=='+'){
			num [i] = num[i]+num[i+1];
		}else{
			num[i] = num[i]*num[i+1];			
		}
		
		num.erase(num.begin()+i+1);
		calc.erase(calc.begin()+i);
	}
};


int calc2(C c){
	while(c.calc.size()!=0){
		
		c.docalc(0);
	}
	return c.num[0];
}
int calc1(C c){
	while(!c.emp()){
		
		rep(i,c.calc.size()){
			if(c.calc[i]=='*'){
				c.docalc(i);
				break;
			}
		}
	}
	
	return calc2(c);
}

int main(){
	string s;
	int n;
	
	cin>>s>>n;
	
	C c;
	rep(i,s.size()){
		if(i%2==0){
			c.num.push_back(s[i]-'0');
		}else{
			c.calc.push_back(s[i]);
		}
	}
	
	
	int n1 = calc1(c);
	int n2 = calc2(c);
	
	char ans = '*';
	if(n1==n && n2==n) ans = 'U';
	if(!(n1==n) && !(n2==n)) ans = 'I';
	if(n1==n && !(n2==n)) ans = 'M';
	if(!(n1==n) && n2==n) ans = 'L';
	
	printf("%c\n",ans);
}