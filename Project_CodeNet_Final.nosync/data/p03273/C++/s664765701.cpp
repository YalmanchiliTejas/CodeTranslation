#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
	int H,W;
	cin>>H>>W;
	int i,j,h=0;
	vector<string> S;
	string str;
	bool bFind;
	for (i=0;i<H;i++){
		cin>>str;
		bFind=false;
		for (j=0;j<W;j++){
			if (str[j]=='#'){
				bFind=true;
				break;
			}
		}
		if (bFind){
			S.push_back(str);
			h++;
		}
	}
	vector<int> col(W,0);
	for (j=0;j<W;j++){
		bFind=false;
		for (i=0;i<h;i++){
			if (S[i][j]=='#'){
				bFind=true;
				break;
			}
		}
		if (!bFind){
			col[j]=1;
		}
	}
	for (i=0;i<h;i++){
		for (j=0;j<W;j++){
			if (col[j]==0){
				cout<<S[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}
