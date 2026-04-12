#include<iostream>
using namespace std;
int main()
{
	int s1[5],s2[5],namae;
	char demise[] = {'A','B','C','D','E'};
	while(1){
		int max=0;
		for(int i=0 ; i<5 ; ++i){
			cin >> s1[i] >> s2[i];
			if(s1[0]==0 && s2[0]==0)break;
		}
		if(s1[0]==0 && s2[0]==0)break;
		for(int i=0 ; i<5 ; ++i){
			if(max<s1[i]+s2[i]){
				max=s1[i]+s2[i];
				namae=i;
			}
		}
		cout << demise[namae] << " " << max << endl;
	}
	return 0;
}