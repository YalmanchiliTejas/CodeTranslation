#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	const string rs = "yuiophjklnm";
	
	while(cin >> s,s!="#"){
		bool r;
		int count=0;
		
		if((int)rs.find(s[0]) != -1) r=true;
		else r = false;
		
		for(int i=1;i<s.size();i++){
			if((int)rs.find(s[i]) != -1 && r == false){
				r = true;
				count++;
			}else if((int)rs.find(s[i]) == -1 && r == true){
				r = false;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}