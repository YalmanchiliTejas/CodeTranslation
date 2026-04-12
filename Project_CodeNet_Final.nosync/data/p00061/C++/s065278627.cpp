#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstdio>

using namespace std;

class CTeam{
public:
	int id;
	int solved;
	int rank;
	bool operator>(const CTeam &t) const{
		if( solved > t.solved ) return true;
		else return false;
	}
};

int main(void){
	int t = 1, rank;
	vector<CTeam> vTeam;
	
	while( true ){
		CTeam tmp;
		scanf("%d,%d", &tmp.id, &tmp.solved);
		if( tmp.id == 0 && tmp.solved == 0 ) break;
		vTeam.push_back( tmp );
	}
	
	sort(vTeam.begin(), vTeam.end(), greater<CTeam>());
	rank = 1;
	vTeam[0].rank = rank;
	for(unsigned int i = 1; i < vTeam.size(); i++){
		if( vTeam[i - 1].solved != vTeam[i].solved ) rank++;
		vTeam[i].rank = rank;
	}
	/*for(unsigned int i = 0; i < vTeam.size(); i++){
		cout << "ID:" << vTeam[i].id << " Solved:" << vTeam[i].solved << " Rank:" << vTeam[i].rank << endl;
	}*/
	while( true ){
		int cid;

		cin >> cid;
		if( cin.eof() ) break;

		for(unsigned int i = 0; i < vTeam.size(); i++){
			if( vTeam[i].id == cid ){
				cout << vTeam[i].rank << endl;
				break;
			}
		}
	}

	return 0;
}