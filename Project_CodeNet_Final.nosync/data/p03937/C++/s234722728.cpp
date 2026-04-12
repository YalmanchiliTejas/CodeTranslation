#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int h,w;
	cin >> h >> w;
	
	char c;
	int cnt=0;
	for(int i=0; i<h*w; i++){
		cin >> c;
		if(c=='#'){
			cnt++;
		}
	}
	if(cnt==h+w-1){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
	
	return 0;
}