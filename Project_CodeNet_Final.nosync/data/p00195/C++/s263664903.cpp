#include <iostream>
using namespace std;

int main() {
	int am,pm;
	int max,max_s;
	
	while(cin>>am>>pm,am||pm){
		max = am + pm;
		max_s = 0;
		for(int i=1;i<5;++i){
			cin>>am>>pm;
			if(max < am + pm){
				max = am + pm;
				max_s = i;
			}
		}
		cout<<(char)('A'+max_s)<<" "<<max<<endl;
	}
	return 0;
}