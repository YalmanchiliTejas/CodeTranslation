#include<iostream>
#include<string>

char right[15] = { 'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b' };
char left[11] = { 'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm' };

char judge(char c){
	for (int i = 0; i < 15; ++i)if (right[i] == c)return 'r';
	return 'l';
}

int main(){
	std::string s;
	while (std::cin>>s){
		if (s == "#")break;
		char shift=judge(s[0]);
		int ans = 0;
		for (int i = 1; i < s.size(); ++i){
			if (shift != judge(s[i])){
				shift = judge(s[i]);
				ans++;
			}
			
		}
		std::cout << ans << std::endl;
		//printf("%c\n", );
	}
}