#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib> //atoi

using namespace std;

int main(){
	char stack[100][1000]={0,0};
	int top[100]={999};
	char result[1000];
	int pos=0;
	int n;
	string s;
	char* b, *c;
	int i;
	int p1 , p2;
	cin >> n;
	while(1){
		getline(cin , s);
		if (s[2]=='s'){ //puSh
			b=(char*)s.c_str();
			b+=5;
			for(i=0 ; ; i++){
				if(b[i]==' ') break;
			}
			b[i]='\0';
			c=b+i+1;
			p1=atoi(b);
			stack[p1][top[p1]--]=c[0];
		} else if (s[2]=='p'){ //poP
			b=(char*)s.c_str();
			b+=4;
			p1=atoi(b);
			result[pos++]=stack[p1][++top[p1]];
		} else if (s[2]=='v'){ //moVe
			b=(char*)s.c_str();
			b+=5;
			for(i=0 ; ; i++){
				if(b[i]==' ') break;
			}
			b[i]='\0';
			p1=atoi(b);
			c=b+i+1;
			p2=atoi(c);;
			stack[p2][top[p2]--]=stack[p1][++top[p1]];
		} else if (s[2]=='i'){ //quIt
			break;
		}
	}
	for(i=0 ; i<pos ; i++){
		cout << result[i] << endl;
	}
	return 0;
}