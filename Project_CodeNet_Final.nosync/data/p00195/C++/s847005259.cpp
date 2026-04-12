#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	while(1){
		pair<int,int> n[5];
		int am,pm;
		for(int i=0;i<5;i++)	cin>>am>>pm,n[i]=make_pair(am+pm,i);
		if(cin.eof())	break;
		sort(n,n+5);
		cout<<(char)('A'+n[4].second)<<' '<<n[4].first<<endl;
	}
	return 0;
}