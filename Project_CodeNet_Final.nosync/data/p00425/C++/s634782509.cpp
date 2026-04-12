#include <iostream>
#include <string>
using namespace std;

struct{
	char s[10];
	int d[6];
} map[6]={
{"North",{1,5,2,0,4,3}},
{"East" ,{2,1,5,3,0,4}},
{"West" ,{4,1,0,3,5,2}},
{"South",{3,0,2,5,4,1}},
{"Right",{0,2,3,4,1,5}},
{"Left" ,{0,4,1,2,3,5}}
};

int main(){
	int n;
	for(;cin>>n,n;){
		string s;
		int i,j,dice[6]={1,5,3,2,4,6},t[6],sum=1;
		for(;n--;){
			cin>>s;
			for(i=0;i<6;i++)t[i]=dice[i];
			for(i=0;i<6;i++)
				if(s==map[i].s)
					for(j=0;j<6;j++) dice[map[i].d[j]]=t[j];
			sum+=dice[0];
		}
		cout << sum << endl;
	}
}