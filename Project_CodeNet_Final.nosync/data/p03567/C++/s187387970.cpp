#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	string s;
	cin >> s;
	bool flag=0,flag1=0;
	for(int i=0;i<s.size();i++){
		if(flag){
			if(s[i]=='A'){
				flag = 1;
			}
			if(s[i]=='C'){
				flag1 = 1;
			}
		}
		if(s[i]=='A'){
			flag = 1;
		}
		if(s[i]!='A'){
			flag = 0;
		}
	}
	if(flag1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}