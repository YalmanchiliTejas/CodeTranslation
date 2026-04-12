#include <iostream>
using namespace std;

int start[6]={2,4,5,3,1,6};
int now[6],next[6];

void ns(int from,int to){
	int d[2][6]={0,5,2,4,1,3,4,0,5,2,1,3};
	for(int i=0;i<6;i++){
		next[d[to][i]] = now[d[from][i]];
	}
}

void ew(int from,int to){
	int d[2][6]={4,3,5,1,2,0,3,5,1,4,2,0};
	for(int i=0;i<6;i++){
		next[d[to][i]] = now[d[from][i]];
	}
}

void rl(int from,int to){
	int d[2][6]={0,1,2,3,4,5,1,2,3,0,4,5};
	for(int i=0;i<6;i++){
		next[d[to][i]] = now[d[from][i]];
	}
}

int main(void){
	int n,sum;
	string s;

	while(cin>>n && n){
		sum = 1;
		copy(start,start+6,now);

		while(n--){
			cin>>s;

			if(s == "North"){ns(0,1);}
			else if(s == "South"){ns(1,0);}
			else if(s == "East"){ew(0,1);}
			else if(s == "West"){ew(1,0);}
			else if(s == "Right"){rl(0,1);}
			else{rl(1,0);}

			copy(next,next+6,now);
			sum += now[4];
		}
		cout<<sum<<endl;
	}

	return 0;
}