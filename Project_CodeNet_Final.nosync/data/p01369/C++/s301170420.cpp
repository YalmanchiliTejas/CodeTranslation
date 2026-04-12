#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }

int main(){
	string left="qazwsxedcrfvtgb";
	string right="yhnujmikolp";
	while(1){
		string s; cin >>s;
		if(s=="#")break;
		bool a=false;
		bool b=false;
		int cnt=0;
		for(int i=0;i<s.size();i++){
			bool c=false;
			for(int j=0;j<11;j++){
				if(s[i]==right[j]){
					b=true;
					if(a==true){
						cnt++;
						a=false;
					}
					c=true;
				}
			}
			if(c==false){
				a=true;
				if(b==true){
					cnt++;
					b=false;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
