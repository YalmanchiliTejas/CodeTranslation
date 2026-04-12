#include <iostream>
#include <vector>

using namespace std;

int main(){
	int H, W;
	string str;
	cin>>H>>W;
	vector < vector <int> > a;
	a.resize(H);
	int cnt=0;
	for(int i=0; i<H; i++){
		a[i].resize(W);
		cin>>str;
		for(int j=0; j<W; j++){
			a[i][j]=str[j];
			if(a[i][j]=='#'){
				cnt++;
			}
		}
	}
	if(cnt==H+W-1){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}

	return 0;
}
