#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
typedef long long ll;
ll INF=1<<29;

int main(){
	ios::sync_with_stdio(false);
	int n,k;
	string s;
	cin>>n>>s>>k;
	char a=s[k-1];
	for(int i=0;i<n;i++){
		if(s[i]!=a){
			cout<<"*";
		}else{
			cout<<s[i];
		}
	}
	return 0;
}
