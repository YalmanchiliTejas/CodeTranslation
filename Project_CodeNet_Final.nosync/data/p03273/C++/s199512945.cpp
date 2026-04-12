//main関数

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int a,b;
	cin>>a>>b;
	vector<vector<char>> p(a,vector<char>(b));
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>p.at(i).at(j);
		}
	}
	vector<bool> A(a,true);
	vector<bool> B(b,true);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(p.at(i).at(j)=='#'){
				A.at(i)=false;
				B.at(j)=false;
			}
		}
	}
	for(int i=a-1;i>=0;i--){
		if(A.at(i)){
			for(int j=i+1;j<a;j++){
				p.at(j-1)=p.at(j);
			}
			a-=1;
		}
	}
	for(int i=b-1;i>=0;i--){
		if(B.at(i)){
			for(int j=0;j<a;j++){
				for(int k=i+1;k<b;k++){
					p.at(j).at(k-1)=p.at(j).at(k);
				}
			}
			b-=1;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cout<<p.at(i).at(j);
		}
		cout<<endl;
	}			
}