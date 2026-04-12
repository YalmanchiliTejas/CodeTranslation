#include <iostream>
using namespace std;
string test(string & start, char & end, string & s)
{
	string ans = start;
	int len = s.size() - 2;
	for(int i = 1; i < len; i++)
	{
		if( s[i] == 'o' and ans[ans.size()-1] == 'S' )
			ans += ans[ans.size()-2];
		else if( s[i] == 'o' and ans[ans.size()-1] == 'W' ){
			if( ans[ans.size()-2] == 'W' )
				ans += 'S';
			else
				ans += 'W';
		}else if( s[i] == 'x' and ans[ans.size()-1] == 'W' )
			ans += ans[ans.size()-2];
		else{
			if( ans[ans.size()-2] == 'W' )
				ans += 'S';
			else
				ans += 'W';
		}
	}
	
	if( s[len] == 'o' and s[len+1] == 'o' )
	{
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] == end and end == 'S' and ans[ans.size()-1] == ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] == end and end == 'W' and ans[ans.size()-1] != ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] != end and end == 'S' and ans[ans.size()-1] == ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] != end and end == 'W' and ans[ans.size()-1] != ans[0] )
			return ans + end;	
	}else if( s[len] == 'o' and s[len+1] == 'x' ){
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] == end and end == 'S' and ans[ans.size()-1] != ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] == end and end == 'W' and ans[ans.size()-1] == ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] != end and end == 'S' and ans[ans.size()-1] != ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] != end and end == 'W' and ans[ans.size()-1] == ans[0] )
			return ans + end;
	}else if( s[len] == 'x' and s[len+1] == 'o' ){
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] != end and end == 'S' and ans[ans.size()-1] == ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] != end and end == 'W' and ans[ans.size()-1] != ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] == end and end == 'S' and ans[ans.size()-1] == ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] == end and end == 'W' and ans[ans.size()-1] != ans[0] )
			return ans + end;
	}else{
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] != end and end == 'S' and ans[ans.size()-1] != ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'S' and ans[ans.size()-2] != end and end == 'W' and ans[ans.size()-1] == ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] == end and end == 'S' and ans[ans.size()-1] != ans[0] )
			return ans + end;
		if( ans[ans.size()-1] == 'W' and ans[ans.size()-2] == end and end == 'W' and ans[ans.size()-1] == ans[0] )
			return ans + end;
	}
	return "-1";
}
int main()
{
	int n;
	string s, tmp;
	cin >> n >> s;
	
	string starter_x[4] = {"SS","SW","WS","WW"};
	char last_x[4] = {'W','S','S','W'};
	  
	string starter_o[4] = {"SW","SS","WW","WS"};
	char last_o[4] = {'W','S','S','W'};
	
	if( s[0] == 'o' )
	{
		for(int i = 0; i < 4; i++)
		{
			tmp = test(starter_o[i],last_o[i],s);
			if( tmp != "-1" )
			{
				cout << tmp;
				return 0;
			}
		}
		cout << "-1";
		return 0;
	}else{
		for(int i = 0; i < 4; i++)
		{
			tmp = test(starter_x[i],last_x[i],s);
			if( tmp != "-1" )
			{
				cout << tmp;
				return 0;
			}
		}
		cout << "-1";
		return 0;
	}
}