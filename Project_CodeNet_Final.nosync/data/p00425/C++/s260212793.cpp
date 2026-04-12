#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(){
	int n;
	string s;
	while(cin>>n&&n){
		int dice[6],cnt=1,t;
		for(int i=0;i<6;i++)dice[i]=i+1;
		while(n--){
			cin>>s;
			if(s=="North"){
				t=dice[0];
				dice[0]=dice[1];
				dice[1]=dice[5];
				dice[5]=dice[4];
				dice[4]=t;
			}else if(s=="East"){
				t=dice[0];
				dice[0]=dice[3];
				dice[3]=dice[5];
				dice[5]=dice[2];
				dice[2]=t;
			}else if(s=="West"){
				t=dice[0];
				dice[0]=dice[2];
				dice[2]=dice[5];
				dice[5]=dice[3];
				dice[3]=t;
			}else if(s=="South"){
				t=dice[0];
				dice[0]=dice[4];
				dice[4]=dice[5];
				dice[5]=dice[1];
				dice[1]=t;
			}else if(s=="Right"){
				t=dice[1];
				dice[1]=dice[2];
				dice[2]=dice[4];
				dice[4]=dice[3];
				dice[3]=t;
			}else{
				t=dice[1];
				dice[1]=dice[3];
				dice[3]=dice[4];
				dice[4]=dice[2];
				dice[2]=t;
			}
			cnt+=dice[0];
		}
		cout<<cnt<<endl;
	}
}