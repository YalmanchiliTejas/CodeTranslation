#include <iostream>
using namespace std;

int main() {
	int n,s;
	char o[6];
	int pos[6]={0,1,2,3,4,5};
	int n_o[6]={4,0,2,3,5,1};
	int e_o[6]={2,1,5,0,4,3};
	int w_o[6]={3,1,0,5,4,2};
	int s_o[6]={1,5,2,3,0,4};
	int r_o[6]={0,3,1,4,2,5};
	int l_o[6]={0,2,4,1,3,5};
	
	while(1){
		int pos[6]={0,1,2,3,4,5};
		s=1;
		cin >> n;
		if(n == 0){return 0;}
		for(int i=0;i<n;i++){
			cin >> o;
			switch( o[0] ){
				case 'N':
				for(int j=0;j<6;j++){
					pos[j]=n_o[pos[j]];
					if(pos[j]==0){s+=1+j;}
				}
				break;
				
				case 'E':
				for(int j=0;j<6;j++){
					pos[j]=e_o[pos[j]];
					if(pos[j]==0){s+=1+j;}
				}
				break;
				
				case 'W':
				for(int j=0;j<6;j++){
					pos[j]=w_o[pos[j]];
					if(pos[j]==0){s+=1+j;}
				}
				break;
				
				case 'S':
				for(int j=0;j<6;j++){
					pos[j]=s_o[pos[j]];
					if(pos[j]==0){s+=1+j;}
				}
				break;
				
				case 'R':
				for(int j=0;j<6;j++){
					pos[j]=r_o[pos[j]];
					if(pos[j]==0){s+=1+j;}
				}
				break;
				
				case 'L':
				for(int j=0;j<6;j++){
					pos[j]=l_o[pos[j]];
					if(pos[j]==0){s+=1+j;}
				}
				break;
			}
		}
		cout << s << endl;
	}
}