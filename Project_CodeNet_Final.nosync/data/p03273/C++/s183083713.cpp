#include <bits/stdc++.h>
using namespace std;
 
int main() {
 	int h,w;cin>>h>>w;
  	vector<vector<char>> s(h,vector<char>(w));//元のデータ
  	vector<vector<char>> t(h,vector<char>(w));//行を除いたデータ
  	vector<vector<char>> u(h,vector<char>(w));//列を除いたデータ
  	int nh=0,nw=0;
  
  	//データをsに格納する。
  	for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
        	cin>>s.at(i).at(j);
        }
    }
  	
  //wの行....分を移行せずにコピー
 	 for(int i=0;i<h;i++){
       bool a=false;
    	for(int j=0;j<w;j++){
        	if(s.at(i).at(j)=='#') a=true;
        }
       
       if(a){
       		for (int k=0;k<w;k++){
        		t.at(nh).at(k)=s.at(i).at(k);
        	}
         nh++;
       }
    }
        
   //hの列....分を移行せずにコピー
 	 for(int i=0;i<w;i++){
       bool a=false;
    	for(int j=0;j<nh;j++){
        	if(t.at(j).at(i)=='#') a=true;
        }
       
       if(a){
       		for (int k=0;k<nh;k++){
        		u.at(k).at(nw)=t.at(k).at(i);
        	}
         nw++;
       }
    }
  
  	for(int i=0;i<nh;i++){
    	for (int k=0;k<nw;k++){
        		cout<<u.at(i).at(k);
        	}
      cout<<endl;
    }
}