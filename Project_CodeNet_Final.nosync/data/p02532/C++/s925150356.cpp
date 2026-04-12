#include<iostream>
#include<string>

//#include <time.h>

using namespace std;

int main(){
	int i,j,sp[100]={0};
	char stack[100][1000];
	string inst;

//  clock_t start,end;
//  start = clock();
	cin >> i;
	while(1){
	cin >> inst;
	if(inst=="quit"){ 
			return 0;
//  end = clock();
//  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
	} 
	else if(inst=="push") {
		cin >> i;
		cin >> stack[i][sp[i]++];
	}
	else if(inst=="pop")	{
		cin >> i;
		cout << stack[i][--sp[i]] << endl;
	}
	else if(inst=="move")	{
		cin >> i >> j;
		stack[j][sp[j]++] = stack[i][--sp[i]];
	}
}
}