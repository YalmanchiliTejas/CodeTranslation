#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
int trmp;
pii deck[4][13];

pii analysis(string &s){
	int a,b;
	if(s[0]>='0'&&s[0]<='9')a=s[0]-'0';
	else if(s[0]=='T')a=10;
	else if(s[0]=='J')a=11;
	else if(s[0]=='Q')a=12;
	else if(s[0]=='K')a=13;
	else if(s[0]=='A')a=14;
	if(s[1]=='S')b=0;
	else if(s[1]=='H')b=1;
	else if(s[1]=='D')b=2;
	else if(s[1]=='C')b=3;
	return pii(a,b);
}

int main(){
	char ch;
	while(cin>>ch&&ch!='#'){
		if(ch=='S')trmp=0;
		else if(ch=='H')trmp=1;
		else if(ch=='D')trmp=2;
		else if(ch=='C')trmp=3;
		for(int i=0;i<4;i++){
			for(int j=0;j<13;j++){
				string s;
				cin>>s;
				deck[i][j]=analysis(s);
			}
		}
		int fst=0;
		int cnt=0;
		int cnt2=0;
		for(int i=0;i<13;i++){
			int winIdx=fst;
			pii p=deck[fst][i];
			for(int j=0;j<4;j++){
				if(j==fst)continue;
				if(deck[j][i].second==trmp){
					if(p.second!=trmp||p.first<deck[j][i].first){
						p=deck[j][i];
						winIdx=j;
					}
				}
				else if(p.second!=trmp&&p.second==deck[j][i].second){
					if(p.first<deck[j][i].first){
						p=deck[j][i];
						winIdx=j;
					}
				}
			}
			if(winIdx==0||winIdx==2)cnt++;
			else cnt2++;
			fst=winIdx;
		}
		if(cnt>cnt2)cout<<"NS "<<abs(cnt-6)<<endl;
		else cout<<"EW "<<abs(cnt2-6)<<endl;
	}

	return 0;
}