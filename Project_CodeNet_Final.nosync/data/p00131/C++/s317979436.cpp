#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool orig[10][10];
bool work[10][10];
bool ans[10][10];


int dx[5] = {-1,0,0,0,1};
int dy[5] = {0,-1,0,1,0};

bool debug = false;

void flip(int x, int y){
	for(int i=0;i<5;i++){
		if(0 <= x+dx[i] && x+dx[i] <10 &&
		0 <= y+dy[i] && y+dy[i] < 10){
			work[x+dx[i]][y+dy[i]] = 1 - work[x+dx[i]][y+dy[i]];
		}
	}
	return;
}


int main(void){
	int n;
	int tmp;
	bool isfirst = true;
	string str;
	
	cin >> n;
	cin.ignore();
	
	for(int cas=0;cas<n;cas++){
		memset(orig, false, sizeof(orig));
		
		//if(!isfirst) cout << endl;
		for(int i=0;i<10;i++){
			getline(cin,str);
			istringstream iss(str);
			if(debug) cout << i << " " << str << endl;
			for(int j=0;j<10;j++){
				iss >> tmp;
				if(tmp == 0){
					orig[i][j] = false;
				}else{
					orig[i][j] = true;
				}
			}
		}
		
		for(int i=0;i < 1 << 10; i++){
			if(debug) cout << i <<endl;
			
			copy(orig, orig+10*10, work);
			//1sÚÉÎ·é
			for(int j=0;j<10;j++){
				if(i & 1 << j){
					flip(0,j);
					ans[0][j] = true;
				}else{
					ans[0][j] = false;
				}
			}
			
			for(int j=1;j<10;j++){
				for(int k=0;k<10;k++){
					if(work[j-1][k]){
						flip(j,k);
						ans[j][k] = true;
					}else{
						ans[j][k] = false;
					}
				}
			}
			
			//check ended or not
			bool isended = true;
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){
					if(work[j][k]){ isended = false;}
				}
			}
			if(isended){
				for(int j=0;j<10;j++){
					for(int k=0;k<10;k++){
						if(k==9){
							cout << ans[j][k] << endl;
						}else{
							cout << ans[j][k] << " ";
						}
					}
				}
				isfirst = false;
				break;
			}
		}
	}
}