#include <iostream>
using namespace std;

int n;
char ope[10];

int main()
{
	int n;
	char ope[10];
	int tmp;
	cin >> n;
	while(n){
		int top=1,N=5,S=2,W=4,E=3,bottom=6;
		int ans = 1;
		for(int i=0;i<n;i++){
			cin >> ope;
			switch(ope[0]){
				case 'N':
					tmp=top; top = S; S=bottom;bottom=N;N=tmp;
					break;
				case 'E':
					tmp=top; top=W; W=bottom; bottom=E; E=tmp;
					break;
				case 'S':
					tmp=top; top=N; N=bottom; bottom=S; S=tmp;
					break;
				case 'W':
					tmp=top; top=E; E=bottom; bottom=W; W=tmp;
					break;
				case 'R':
					tmp=S; S=E; E=N; N=W; W=tmp; 
					break;
				case 'L':
					tmp=S; S=W; W=N; N=E; E=tmp;
					break;
			}
			ans += top;
		}
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}