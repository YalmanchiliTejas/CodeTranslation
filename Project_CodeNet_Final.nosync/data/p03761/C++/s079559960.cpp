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
int N;
vector<map<char,int>> S(50);

cin>>N;
fx(N){
	string A;
	cin>>A;
	fy(A.size()){
	S.at(x)[A.at(y)]++;
	}
}
char kind='B'-'A';
string ans;
fx(26){
	char k='a'+kind*x;
	int min=51;
	fy(N){
		if(min>S.at(y)[k]){
			min=S.at(y)[k];
		}
	}
	while(min-->0){
		ans+=k;
	}
}

ce(ans);

}