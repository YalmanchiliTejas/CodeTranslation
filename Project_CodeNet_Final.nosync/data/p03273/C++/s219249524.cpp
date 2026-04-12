#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define ces(d) cout<<" "<<endl;

int main() {

int H,W;
vector<string> G(100);
cin>>H>>W;
fx(H){

		cin>>G.at(x);
	
}

	
	fx(H){
		int a=0;
	fy(W){
		if(G.at(x).at(y)=='.'){
			a++;
		}
	}
	if(a==W){
		fy(W){
		G.at(x).at(y)='0';
	    }
	}
	}
	
		fx(W){
		int a=0;
	fy(H){
		if(G.at(y).at(x)=='.'||G.at(y).at(x)=='0'){
			a++;
		}
	}
	if(a==H){
		fy(H){
		G.at(y).at(x)='0';
	    }
	}
	}
	

fx(H){
bool flag=false;
	fy(W){
		if(G.at(x).at(y)!='0'){
		cout<<G.at(x).at(y);
flag=true;
		}
	}
if(flag){
	cout<<endl;
}
}

}