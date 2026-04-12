#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	string table = "qwertasdfgzxcvb";
	string str;
	while(cin >> str , str != "#"){
		string ans;
		rep(i,str.size()){
			ans += '0' + !!count(table.begin(),table.end(),str[i]);
		}
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		cout << ans.size()-1 << endl;
	}
}