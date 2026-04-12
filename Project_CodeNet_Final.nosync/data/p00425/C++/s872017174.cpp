#include<iostream>
#include<cstring>
using namespace std;
struct dice{
	int court[6];
	dice(int c[6]){court[0]=c[0];court[1]=c[1];court[2]=c[2];court[3]=c[3];court[4]=c[4];court[5]=c[5];}
	dice(){}
	void roll(char *ch);
	int top(){return court[0];}
};

void dice::roll(char *ch){
	int tmp;
	if(!strcmp("North", ch)){
		tmp = court[0];
		court[0] = court[1];
		court[1] = court[5];
		court[5] = court[4];
		court[4] = tmp;
	}
	if(!strcmp("East", ch)){
		tmp = court[0];
		court[0] = court[3];
		court[3] = court[5];
		court[5] = court[2];
		court[2] = tmp;
	}
	if(!strcmp("West", ch)){
		tmp = court[0];
		court[0] = court[2];
		court[2] = court[5];
		court[5] = court[3];
		court[3] = tmp;
	}
	if(!strcmp("South", ch)){
		tmp = court[0];
		court[0] = court[4];
		court[4] = court[5];
		court[5] = court[1];
		court[1] = tmp;
	}
	if(!strcmp("Right", ch)){
		tmp = court[1];
		court[1] = court[2];
		court[2] = court[4];
		court[4] = court[3];
		court[3] = tmp;
	}
	if(!strcmp("Left", ch)){
		tmp = court[1];
		court[1] = court[3];
		court[3] = court[4];
		court[4] = court[2];
		court[2] = tmp;
		}
	return;
}

int main(){
	int n, sum;
	int a[6] = {1,2,3,4,5,6};
	char ch[10];
	while(true){
		cin >> n;
		dice d(a);
		sum=d.top();
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin>>ch;
			d.roll(ch);
			sum += d.top();
		}
		cout << sum << endl;
	}
	return 0;
}