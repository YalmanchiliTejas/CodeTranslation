#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <istream>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
int main(){
	string s;
	int k;
	cin>>s>>k;
	if(s.size()<k){
		cout<<0<<endl;
		return 0;
	}
	if(s.size()==1){
		if(k==1)cout<<9<<endl;
		return 0;
	}
	long long cnt=0LL;
	for(int i=k;i<s.size();i++){
		if(k==1)cnt+=1LL*9;
		else if(k==2)cnt+=1LL*9*(i-1)*9;
		else cnt+=1LL*9*(i-1)*(i-2)/2*81;
	}
	if(k==1){
		cnt+=(int)(s[0]-'0');
	}
	else if(k==2){
		cnt+=1LL*(int)(s[0]-'0'-1)*(s.size()-1)*9;
		for(int j=1;j<s.size();j++){
			if(j+1==s.size()){
				cnt+=(int)(s[j]-'0');
				break;
			}
			if((int)(s[j]-'0')>0){
				cnt+=1LL*(int)(s[j]-'0');
				cnt+=1LL*(s.size()-j-1)*9;
				break;
			}
		}
	}
	else{
		cnt+=1LL*(int)(s[0]-'0'-1)*(s.size()-1)*(s.size()-2)/2*81;
		int num=0;
		for(int i=1;i<s.size();i++){
			if((int)(s[i]-'0')>0){
				num=i;
				break;
			}
		}
		if(!num){
			cout<<cnt<<endl;
			return 0;
		}
		if(num+2==s.size()){
			if((int)(s[num+1])>0){
				cnt+=(int)(s[num]-'0')*(int)(s[num+1]-'0');
			}
			cout<<cnt<<endl;
			return 0;
		}
		if(num+2>s.size()){
			cout<<cnt<<endl;
			return 0;
		}
		cnt+=(s.size()-num-1)*(s.size()-num-2)/2*81;
		cnt+=(int)(s[num]-'0'-1)*(s.size()-num-1)*9; 
		for(int j=num+1;j<s.size();j++){
			if(j+1==s.size()){
				cnt+=(int)(s[j]-'0');
				break;
			}
			if((int)(s[j]-'0')>0){
				cnt+=1LL*(int)(s[j]-'0');
				cnt+=1LL*(s.size()-j-1)*9;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}