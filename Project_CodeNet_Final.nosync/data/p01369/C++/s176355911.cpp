#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;

bool find(char c){
	vector<char> left = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
	for (int i = 0; i < left.size(); i++){
		if (c == left[i]) return true;
	}
	return false;
}
int main(){
	vector<char> right = {'y','u','i','o','p','h','j','k','l','n','m'};
	
	while(1){
		int ans = 0;

		string str; cin >> str;
		if (str == "#") break;
		
		bool left_flag  = find(str[0]);
		bool right_flag = !find(str[0]);

		for (int i = 0; i < str.size(); i++){
			if (find(str[i]) and !left_flag){
				ans++;
				left_flag = true;
				right_flag = false;
			}else if(!find(str[i]) and !right_flag){
				left_flag = false;
				right_flag = true;
				ans++;
			}
				
		}
		cout << ans << endl;
	}

return 0;
}