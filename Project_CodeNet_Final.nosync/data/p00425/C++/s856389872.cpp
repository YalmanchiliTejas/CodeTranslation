#include <bits/stdc++.h>
#define ch(x,y) strstr(x,y)
using namespace std;
int main(void)
{
	int a,t=1;
	int n=5,e=3,w=4,s=2,o=1,u=6;
	char b[10];
	cin >> a;
	while(a != 0){
		for(int i = 0;i < a;i++){
			cin >> b;
			if(ch(b,"North") != NULL){
				swap(n,o);
				swap(o,s);
				swap(s,u);
			}
			if(ch(b,"East") != NULL){
				swap(e,o);
				swap(o,w);
				swap(w,u);
			}
			if(ch(b,"West") != NULL){
				swap(w,o);
				swap(o,e);
				swap(e,u);
			}
			if(ch(b,"South") != NULL){
				swap(s,o);
				swap(o,n);
				swap(n,u);
			}
			if(ch(b,"Right") != NULL){
				swap(n,w);
				swap(w,s);
				swap(s,e);
			}
			if(ch(b,"Left") != NULL){
				swap(n,e);
				swap(e,s);
				swap(s,w);
			}
			t += o;
		}
		cout << t << endl;
		n=5;
		e=3;
		w=4;
		s=2;
		o=1;
		u=6;
		t = 1;
		cin >> a;
	}
	
	return 0;
}