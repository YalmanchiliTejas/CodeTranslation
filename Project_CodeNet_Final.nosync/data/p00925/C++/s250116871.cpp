#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <iomanip>
#include <stack>
  
using namespace std;

#define pi 3.141592653589793


//  + を -1　* を -11
int multiplication_first(string s)
{
	stack<int> calculation;
	int cnt = 0;
	while(cnt < s.length()){
		if(isdigit(s[cnt])){
			calculation.push(s[cnt] - '0');
		} else if(s[cnt] == '*'){
			int result = calculation.top() * (s[cnt + 1] - '0');
			calculation.pop();
			calculation.push(result);
			cnt++;
		}
		cnt++;
	}
	while(calculation.size() != 1){
		int top = calculation.top();
		calculation.pop();
		int second = calculation.top();
		calculation.pop();
		calculation.push(top + second);
	}
	return calculation.top();
}

int left_to_right(string s)
{
	int ans = s[0] - '0';
	int cnt = 1;
	while(cnt < s.length()){
		if(s[cnt] == '+'){
			ans += s[cnt + 1] - '0';
			cnt++;
		} else if(s[cnt] == '*'){
			ans = ans * (s[cnt + 1] - '0');
			cnt++;
		}
		cnt++;
	}
	return ans;	
}

int main()
{
	string s;
	int bobans;
	cin >> s >> bobans;
	int ans[2] ={};
	// ans[0]:multiplication_firstとあっているか　ans[1]:left_to_rightとあっているか　あってたら1
	if(bobans == multiplication_first(s)) ans[0]++;
	if(bobans == left_to_right(s)) ans[1]++;
	if(ans[0] && ans[1]) cout << 'U' << endl;
	else if(ans[0]) cout << 'M' << endl;
	else if(ans[1]) cout << 'L' << endl;
	else cout << 'I' << endl;
	return 0;
}