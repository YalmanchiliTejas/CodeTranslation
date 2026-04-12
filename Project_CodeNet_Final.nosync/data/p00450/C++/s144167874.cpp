#include <iostream>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0; i<(int)(n); i++)

class _stone{
public:
	int begin,end;
	_stone(int s,int e){
		begin = s;
		end   = e;
	}
};

int main(){
	int n;
	while(cin>>n,n){
		vector<_stone> stone[2];
		for(int i=1; i<=n; i++){
			int color; cin>>color;
			if( i%2==0 ){ //even
				if( !stone[color^1].empty() && stone[color^1][stone[color^1].size()-1].end==i-1 ){
					if( stone[color].empty() ){
						stone[color].push_back( _stone(1,i) );
						stone[color^1].pop_back();
					}else{
						stone[color][stone[color].size()-1].end = i;
						stone[color^1].pop_back();
					}
				}else{
					if( stone[color].empty() ) stone[color].push_back( _stone(i,i) );
					else                       stone[color][stone[color].size()-1].end = i;
				}
			}else{ //odd
				if( stone[color].empty() || stone[color][stone[color].size()-1].end != i-1)
					stone[color].push_back( _stone(i,i) );
				else
					stone[color][stone[color].size()-1].end = i;
			}
			/*
			printf("i:%d\n",i);
			REP(j,stone[0].size())printf("w:%d_%d\n",stone[0][j].begin,stone[0][j].end);
			REP(j,stone[1].size())printf("b:%d_%d\n",stone[1][j].begin,stone[1][j].end);
			*/
		}
		int ans = 0;
		for(int i=0; i<stone[0].size(); i++){
			ans += stone[0][i].end - stone[0][i].begin + 1;
			//printf("%d_%d\n",stone[0][i].begin,stone[0][i].end);
		}
		printf("%d\n",ans);
	}
	return 0;
}