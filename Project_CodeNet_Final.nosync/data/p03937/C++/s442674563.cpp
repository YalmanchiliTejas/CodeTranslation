#include<bits/stdc++.h>
using namespace std;
int main(){
	int H, W;
	char A;
	scanf("%d %d", &H, &W);
	int cnt = 0;
	while(scanf("%c", &A) != EOF){
		if(A == '#') cnt++;
	}
	if(cnt == H + W - 1) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
