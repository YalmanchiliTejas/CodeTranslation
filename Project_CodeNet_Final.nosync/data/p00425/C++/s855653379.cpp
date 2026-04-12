#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int top, front, a;

void dice(string str);

int main(void)
{
	int n;
	while (scanf("%d", &n), n){
		string str;
		int res = 1;
		top = 1;
		front = 2;
		a = 3;
		for (int i = 0; i < n; i++){
			cin >> str;
			dice(str);
			res += top;
		}
		printf("%d\n", res);
	}
	
	return 0;
}

void dice(string str)
{
	int tmp;
	if (str == "North"){
		tmp = top;
		top = front;
		front = 7 - tmp;
	}
	if (str == "East"){
		tmp = a;
		a = top;
		top = 7 - tmp;
	}
	if (str == "West"){
		tmp = top;
		top = a;
		a = 7 - tmp;
	}
	if (str == "South"){
		tmp = front;
		front = top;
		top = 7 - tmp;
	}
	if (str == "Right"){
		tmp = front;
		front = a;
		a = 7 - tmp;
	}
	if (str == "Left"){
		tmp = a;
		a = front;
		front = 7 - tmp;
	}
}