#include <iostream>
#include <vector>
using namespace std;

int main(){
	while(1){
		string s;
		cin >> s;
		if(s=="#") break;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		vector<vector<bool> > field(9, vector<bool>(9,false));;
		int x=0, y=0;
		for(int i=0; i<(int)s.length(); i++){
			if(s[i]=='/'){
				y++;
				x = 0;
			}else if(s[i]=='b'){
				field[y][x]=true;
				x++;
			}else{
				x += s[i]-'0';
			}
		}
		y++;		
		field[a-1][b-1] = false;
		field[c-1][d-1] = true;
		
		for(int i=0; i<y; i++){
			for(int j=0; j<x; j++){
				if(field[i][j]){
					cout << "b";
				}else{
					int count=0;
					for(int k=j; ; k++){
						if(k>=x || field[i][k]){
							cout << count;
							j=k-1;
							break;
						}else{
							count++;
						}
					}
				}
			}
			if(i<y-1) cout << "/";
		}
		cout << endl;
	}
	return 0;
}