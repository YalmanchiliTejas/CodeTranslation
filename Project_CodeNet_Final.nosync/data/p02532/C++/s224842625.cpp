#include <iostream>
#include <string>
#include <stack>

using namespace std;
	int main(void){
	int num,num2;
	char tem;
	string s1,s2,s3,s4,tar;
	stack <char> t[101];
	s1="push";
	s2="pop";
	s3="quit";
	s4="move";
	cin >> num;
	while( cin >> tar, tar!=s3){
		if(tar == s1){
			cin >> num;
			cin >> tem,t[num].push(tem);
		}
		else if(tar ==s2){
			cin >> num;
			cout << t[num].top() << endl,t[num].pop();
		}else{
			cin >> num >> num2;
			t[num2].push(t[num].top());
			t[num].pop();
		}
	}
	return 0;
}