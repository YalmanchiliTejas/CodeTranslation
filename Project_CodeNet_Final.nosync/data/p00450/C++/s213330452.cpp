#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,i,j,c,white_cnt;
	//int d;///////debug
	
	while(true){
		cin >> n;
		if(n == 0)break;
		white_cnt = 0;
		vector<int> table(n);
		for(i = 0; i < n; i++){
			cin >> c;
			if((i+1)%2 == 0){
				table[i] = c;
				if(table[i-1] != c){
					for(j=i-1;j>=0;j--){
						if(table[j] != c){
							table[j] = c;
						}else{
							break;
						}
					}
				}
			}else{
				table[i] = c;
			}
			/////////////coco/////////////
			/*
			for(d=0;d<=i;d++){
				if(table[d]){
					cout<<"x";
				}else{
					cout<<"o";
				}
			}
			cout<<endl;
			*/
			/////////////made/////////////
		}
		for(i=0;i<n;i++){
			if(table[i] == 0){
				white_cnt++;
			}
		}
		cout << white_cnt << endl;
	}
	return 0;
}