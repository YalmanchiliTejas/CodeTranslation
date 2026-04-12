#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
stack<char> a[100];
char c;
int n,p,p2;
string str;
cin >> n;
while(1){
	cin >> str;
	if(str=="pop"){
	cin >> p;
	cout << a[p].top() <<endl;
	a[p].pop();
	}
	else if(str=="push"){
	cin >> p >> c;
	a[p].push(c);
	}
	else if(str=="move"){
	cin >> p >> p2;
	a[p2].push(a[p].top());
	a[p].pop();
	}
	else if(str=="quit") break;
}
return 0;
}