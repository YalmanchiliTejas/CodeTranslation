#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	string str;
	cin >> str;
	bool flag=false;
	for(int i=0;i<str.size()-1;i++){
		if(str[i]=='A' && str[i+1]=='C'){
			flag=true;
		}
	}
	printf("%s\n",flag?"Yes":"No");
	return 0;
}