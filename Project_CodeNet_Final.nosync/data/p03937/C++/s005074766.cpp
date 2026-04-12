#include<iostream>
using namespace std;
int main(){
	char ch;
	int h,w,count=0;
	cin >> h >> w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
				cin >> ch;
				if(ch=='#')	count++;
		}
	}
	if((h+w-1)==count)	cout << "Possible\n";
	else	cout << "Impossible\n";
}