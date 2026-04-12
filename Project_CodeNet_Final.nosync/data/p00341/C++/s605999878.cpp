#include<bits/stdc++.h>

using namespace std;
int main()
{
	vector<int> e;
	
	for(int i=0;i<12;i++){
		e.push_back(0);
		cin>>e[i];
	}
	
	sort(e.begin(),e.end());
	
	if( e[0]==e[1] && e[1]==e[2] && e[2]==e[3] && e[4]==e[5] && e[5]==e[6] && e[6]==e[7] && e[8]==e[9] && e[9]==e[10] && e[10]==e[11] )
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
}

