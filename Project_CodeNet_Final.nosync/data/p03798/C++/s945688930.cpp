#include <iostream>
using namespace std;
int N;
char s[100008*3];
bool line[100008]={false}; // 0=s 1=w
bool d[4][2] = {
		{false,false},
		{false,true},
		{true,false},
		{true,true},
};
int main() {
	scanf("%d%s",&N,s);
	bool found = false;
	for(int i=0;i<4;i++){
		line[0] = d[i][0];line[1] = d[i][1];
		for(int j=1;j<N-1;j++){
			if(s[j]=='o' != line[j]){
				line[j+1]=line[j-1];
			}else{
				line[j+1]=!line[j-1];
			}
		}
		found=
				  (( line[1]==line[N-1] ) == ( (line[0]) != ( s[0]=='o' ) ) )
				&&(( line[0]==line[N-2] ) == ( (line[N-1]) != ( s[N-1]=='o' ) ) );
		if(found)break;
	}
	if(found){
		for(int i=0;i<N;i++)printf(line[i] ? "W":"S");
		printf("\n");
	}else printf("-1\n");
	return 0;
}
