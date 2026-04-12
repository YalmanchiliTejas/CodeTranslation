#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;cin>>h>>w;vector<vector<char>> A(105,vector<char>(105)),B(105,vector<char>(105)),C(105,vector<char>(105));int countw=0,counth=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>A.at(i).at(j);
		}
    }
	for(int i=0;i<h;i++){
		int count=0;
		for(int j=0;j<w;j++){
			if(A.at(i).at(j)=='.') count++;
        }
        if(count!=w){
	        for(int j=0;j<w;j++){
    	    	B.at(counth).at(j)=A.at(i).at(j);
        	}
			counth++;
        }
	}
    for(int j=0;j<w;j++){
        int count=0;
        for(int i=0;i<counth;i++){
            if(B.at(i).at(j)=='.') count++;
        }
        if(counth!=count){
            for(int i=0;i<counth;i++){
	            C.at(i).at(countw)=B.at(i).at(j);
        	}
			countw++;
    	}
	}
    for(int i=0;i<counth;i++){
        for(int j=0;j<countw;j++){
            cout<<C.at(i).at(j);
        }
        cout<<endl;
    }
}