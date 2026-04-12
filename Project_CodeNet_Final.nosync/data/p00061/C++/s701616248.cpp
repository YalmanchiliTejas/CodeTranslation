#include<iostream>
#include<algorithm>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)

struct num{
	int a;
	int b;
	int rank;
};

int main(void){
	struct num data[200];
	int indata[200];
	struct num w;
	
	char c;
	int i=0,rank=0;
	while(cin>>data[i].a>>c>>data[i].b,data[i].a+data[i].b)i++;
//	cout<<i<<endl;
	loop(j,0,i-1){
		loop(k,j,i){
			if(data[j].b<data[k].b){
				w=data[j];data[j]=data[k];data[k]=w;
			}
		}
		if(data[j].b==data[j-1].b)data[j].rank=rank;
		else data[j].rank=++rank;
	}
	if(data[i-2].b==data[i-1].b)data[i-1].rank=rank;
	else data[i-1].rank=++rank;
	int d=0;
	while(cin>>indata[d++]);
	
	for(int j=0;j<d;j++){
		for(int k=0;k<i;k++){
			if(indata[j]==data[k].a)cout<<data[k].rank<<endl;
		}
	}

	
	
//	for(int j=0;j<i;j++)cout<<data[j].a<<" "<<data[j].b<<" "<<data[j].rank<<endl;
	
	
}