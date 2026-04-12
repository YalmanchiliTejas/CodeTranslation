#include <iostream>
using namespace std;

typedef struct{
	string name;
	int score;
}Team;

int main(void){
	int n;
	bool firstFlg = true;
	
	while(cin>>n && n){
		if(!firstFlg) cout<<endl;
		else firstFlg = false;
	
		Team t[n];
		for(int i=0;i<n;i++){
			int win,lose,draw;
			
			cin>>t[i].name>>win>>lose>>draw;
			t[i].score = win*3 + draw;
		}
		
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1;j++){
				if(t[j].score < t[j+1].score){
					Team tmp = t[j];
					t[j] = t[j+1];
					t[j+1] = tmp;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			cout<<t[i].name<<","<<t[i].score<<endl;
		}
	}

	return 0;
}