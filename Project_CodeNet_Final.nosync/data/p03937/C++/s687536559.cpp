#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string>

using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
	int h, w;cin>>h>>w;
	bool ans=true;
	vector<vector<char>> field(h, vector<char>(w));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>field[i][j];
		}
	}
	int start=0;
	for(int i=0;i<h;i++){
		bool fin=false;
        if(field[i][start]!='#'){ans=false;break;}
		for(int j=0;j<w;j++){
			if(field[i][j]=='#'&&j<start){ans=false;break;}
			if(!fin&&(field[i][j]=='.'&&j>start)){start=j-1;fin=true;}
			else if(fin&&field[i][j]=='#'){ans=false;break;}
		}
        if(field[i][w-1]=='#')start=w-1;
		if(!ans)break;
	}
	cout << (ans?"Possible":"Impossible") << endl;
}
