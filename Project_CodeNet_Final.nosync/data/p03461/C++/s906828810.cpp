#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_A=10,MAX_B=10,INF=1e5;
int A,B,d[MAX_A][MAX_B];

int f[101][101];

int main(){
	cin>>A>>B;
	REP(i,A)REP(j,B){
		cin>>d[i][j];
	}
	REP(a,101){
		REP(b,101){
			REP(x,A){
				REP(y,B){
					f[a][b]=max(f[a][b],d[x][y]-(x+1)*a-(y+1)*b);
				}
			}
		}
	}
	bool ans=true;
	REP(x,A){
		REP(y,B){
			int td=INF;
			REP(a,101){
				REP(b,101){
					td=min(td,(x+1)*a+(y+1)*b+f[a][b]);
				}
			}
			if (td!=d[x][y]){
				ans=false;
			}
		}
	}
	if (ans){
		cout<<"Possible"<<endl<<101*2<<" "<<101*101+200<<endl;
		REP(i,100){
			cout<<i+1<<" "<<i+2<<" X"<<endl;
		}
		REP(i,100){
			cout<<i+102<<" "<<i+103<<" Y"<<endl;
		}
		REP(a,101){
			REP(b,101){
				cout<<a+1<<" "<<202-b<<" "<<f[a][b]<<endl;
			}
		}
		cout<<"1 202"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}