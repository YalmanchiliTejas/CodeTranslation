#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

string str;
string str2;

int main(void){
	cin >> str;
	cin >> str2;
	int now=0;
	int cnt=0;
	int ng=0;
	bool flag=true;
	for(int i=0;i<str.size();i++){
		if(now<str2.size() && str[i]==str2[now]){
			now++;
		}else{
			if(str[i]==str2[now-1]){
				flag=false;
			}
			if(ng<str2.size() && str[i]==str2[ng]){
				ng++;
			}
		}
	}
	if(ng==str2.size())flag=false;
	printf("%s\n",(now==str2.size() && flag)?"yes":"no");
	return 0;
}