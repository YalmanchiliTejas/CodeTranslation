 #include<bits/stdc++.h>
    using namespace std;
    int main(){
		int h,w;
		string s[10];
		cin>>h>>w;
		for(int i=0;i<h;i++){
			cin>>s[i];
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(s[i][j]=='#'){
				if(i!=h-1 && j!=w-1){
				if(s[i+1][j]=='#' && s[i][j+1]=='#' || s[i+1][j]!='#' && s[i][j+1]!='#'){
					cout<<"Impossible"<<endl;
					return(0);
				}
				}
				}
				if(i!=0 && j!=0){
				if(s[i-1][j]=='#' && s[i][j-1]=='#'){
					cout<<"Impossible"<<endl;
					return(0);
				}
				}
			}
		}
		cout<<"Possible"<<endl;
      return(0);
    }