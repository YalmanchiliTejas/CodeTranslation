#include <iostream>
using namespace std;
int main(){
	int H,W,c=0;
	char a;
	cin>>H>>W;
	while(cin>>a)c+=a=='#';
	cout<<(c==H+W-1?"P":"Imp")<<"ossible\n";
}