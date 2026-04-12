#include <iostream>
#include <string>

using namespace std;

int main(void){
	bool 	first=true;
	string	team;
	int	w,d,l;

	for(int n;cin >> n,n;){
		pair<string,int> *val,tmp;

		val = new pair<string,int>[n];

		for(int i=0;i<n;i++){
			cin >> team >> w >> l >> d;
			val[i]=make_pair(team,w*3+d);
		}

		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-i-1;j++)
				if(val[j].second<val[j+1].second){
					tmp=val[j];
					val[j]=val[j+1];
					val[j+1]=tmp;
				}

		if(!first)
			cout << endl;
		else
			first=false;

		for(int i=0;i<n;i++)
			cout << val[i].first << "," << val[i].second << endl;
		delete [] val;
	}
	return 0;
}