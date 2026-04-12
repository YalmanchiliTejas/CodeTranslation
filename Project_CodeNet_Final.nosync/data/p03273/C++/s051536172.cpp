#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    vector<int> col, row;
    cin >> H >> W;
    string map[H+1];
    bool flag;
    
    for(int i=0; i<H;i++){
	cin >> map[i];
    }

    for(int i=0; i<H;i++){
	flag=false;
	for(int j=0; j<W; j++){
	    if(map[i][j]=='#'){
		flag=true;
		break;
	    }
	}
	if(flag){
	    row.push_back(i);		    
	}
    }

    for(int i=0; i<W;i++){
	flag=false;
	for(int j=0; j<H; j++){
	    if(map[j][i]=='#'){
		flag=true;
		break;
	    }
	}
	if(flag){
	    col.push_back(i);
	}
    }

    for(int i=0; i<row.size(); i++){
	for(int j=0; j<col.size(); j++){
	    int left=row[i];
	    int right = col[j];
	    cout<<map[left][right];
	}
	cout<<endl;
    }
}
