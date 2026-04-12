#include <iostream>
#include <string>
using namespace std;

bool check_fizz_buzz(int n, string s){
	if(n % 15 == 0)
		return (s == "FizzBuzz");
	else if(n % 3 == 0)	
		return (s == "Fizz");
	else if(n % 5 == 0)
		return (s == "Buzz");
	
	for(unsigned int i = 0; i < s.size(); ++i)
		if(s[i] < '0' || s[i] > '9')
			return false;
			
	return (n == atoi(s.c_str()));
}

int main() {
	int n, m;
	string s;
	while(1){
		cin >> m >> n;
		if(m == 0 && n == 0)
			break;
		bool srv[1001] = {false};
		int now = 1 , count = 0;
		for(int i = 1; i <= n; ++i){
			cin >> s;
			if(count >= m - 1)
				continue;

			if(!check_fizz_buzz(i, s)){
				srv[now] = true;
				count++;
			}
			now++;
			while(srv[now])
				now++;
			if(now >= m + 1)
				now = 1;
			while(srv[now])
				now++;
		}
		int ans[1000] = {0};
		bool end = true;
		for(int i = 0; i < m && end; ++i){
			for(int j = 1; j <= m; ++j){
				if(!srv[j]){
					ans[i] = j;
					srv[j] = true;
					break;
				}
				if(j == m - 1)
					end = false;
			}
		}
			
		for(int i = 0; i < m; ++i){
			if(ans[i] == 0)
				continue;
			if(i)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}