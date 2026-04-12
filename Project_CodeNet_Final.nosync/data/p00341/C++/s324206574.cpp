#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int i;
	vector<int> c;
	for(i=0;i<12;i++){
		int temp;
		cin>>temp;
		c.push_back(temp);
    }
	sort(c.begin(),c.end());
	if(c[0]==c[1] && c[1]==c[2] && c[2]==c[3]&&c[4]==c[5] && c[5]==c[6] && c[6]==c[7]&&c[8]==c[9] && c[10]==c[9] && c[10]==c[11])
    cout<<"yes"<<endl;

	else
	cout<<"no"<<endl;
	return 0;
}

