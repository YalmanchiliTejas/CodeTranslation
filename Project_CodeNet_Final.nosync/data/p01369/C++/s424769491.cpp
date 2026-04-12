#include<iostream>
#include<string>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

char typing[11]={'y','u','i','o','p','h','j','k','l','n','m'};

int main(){
	string s;
	while(1){
		cin>>s;
		if(s=="#")break;
		bool hand=true;
		rep(i,11)if(s[0]==typing[i])hand=false;
		int count=0;
		loop(i,1,s.size()){
			if(hand){
				rep(j,11){
					if(s[i]==typing[j]){
						count++;
						hand=!hand;
						break;
					}
				}
			}else{
				bool check=false;
				rep(j,11)if(s[i]==typing[j]){check=true;break;}
				if(check)continue;
				count++;
				hand=!hand;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}