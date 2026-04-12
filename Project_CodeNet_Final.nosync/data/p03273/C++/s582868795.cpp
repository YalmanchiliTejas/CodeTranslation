#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  	int H,W;
  	cin>>H>>W;
	vector<string>s(H);
  	for(int i=0;i<H;++i)cin>>s[i];
  	vector<bool>x(H,false);
  	vector<bool>y(W,false);
  	for(int i=0;i<H;++i){
    	for(int j=0;j<W;++j)if(s[i][j]=='#'){x[i]=true;y[j]=true;}
    }for(int i=0;i<H;++i){
    	for(int j=0;j<W;++j)if(x[i]&&y[j])cout<<s[i][j];
      	cout<<endl;
    }
	return 0;
}