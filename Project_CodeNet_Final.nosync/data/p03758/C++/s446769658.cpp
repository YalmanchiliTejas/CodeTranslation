#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<P> res;

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(res.size()==n-1)break;
			string str="";
			for(int k=0;k<n;k++){
				if(i==k || j==k)str+='1';
				else str+='0';
			}
			cout << "? " << str << endl;
			int v;
			scanf("%d",&v);
			if(v!=0)res.push_back(P(i,j));
		}
	}
	string res2="! ";
	for(int i=0;i<res.size();i++){
		res2+='(';
		string num="";
		while(res[i].first>0){
			num+=(res[i].first%10+'0');
			res[i].first/=10;
		}
		if(num.size()==0)num+='0';
		reverse(num.begin(),num.end());
		res2+=num;
		res2+=',';
		num="";
		while(res[i].second>0){
			num+=(res[i].second%10+'0');
			res[i].second/=10;
		}
		if(num.size()==0)num+='0';
		reverse(num.begin(),num.end());
		res2+=num;
		res2+=')';
		if(i+1!=res.size())res2+=' ';
	}
	cout << res2 << endl;
	return 0;
}
