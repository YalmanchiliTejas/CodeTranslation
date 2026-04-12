#include <iostream>
#include <algorithm>
using namespace std;

class Team{
public:
	int id,score;
	string name;
	Team(){}
	Team(int _id,int _score,string _name){
		id = _id;
		score = _score;
		name = _name;
	}
	bool operator<(const Team t)const{
		if(score == t.score) return id < t.id;
		return score > t.score;
	}
};

int main(void){
	int n;
	bool first = true;

	while(cin>>n,n){
		if(first) first = false;
		else cout<<endl;

		Team t[n];
		for(int i=0;i<n;i++){
			string name;
			int a,b,c;
			cin>>name>>a>>b>>c;
			t[i] = Team(i,3*a+c,name);
		}
		sort(t,t+n);
		for(int i=0;i<n;i++){
			cout<<t[i].name<<","<<t[i].score<<endl;
		}
	}

	return 0;
}