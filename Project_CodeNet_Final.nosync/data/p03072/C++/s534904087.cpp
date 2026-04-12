#include <iostream>
using namespace std;

int h[101];

int main(){
	int n,i,max=0,br=0;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> h[i];
		if(h[i]>=max){
			br++;
			max=h[i];
		}
	}
	cout << br;
		
	
}
