#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,a) for(int i=0;i<a;i++)
int goisi[1000000];
int hennka[1000000];

int kaitou(){
	int kosu;
	cin>>kosu;
	if(kosu==0){return 1;}
	FOR(i,kosu){cin>>goisi[i];}
	int lastgoisi=0;
	int lasthennka=0;
	FOR(i,kosu){
		if(i%2==0){
			if(goisi[i]!=lastgoisi){
					lastgoisi=goisi[i];
					hennka[lasthennka]=i;
					lasthennka++;
				}
		}
		if(i%2==1){
			if(goisi[i]!=lastgoisi){
				lastgoisi=goisi[i];
				if(lasthennka!=0){hennka[lasthennka-1]=0;lasthennka--;}
			}
		}
	}
	int ans=0;
	for(int i=lasthennka-1;i>=0;i=i-2){
		if(i!=0){ans=ans+hennka[i]-hennka[i-1];}
		else{ans=ans+hennka[0];}
	}
	if(lastgoisi==0){ans=kosu-ans;}
	cout<<ans<<endl;return 0;
}

int main(){
while(1){
	int r=kaitou();
	if(r==1){break;}
}
return 0;
}