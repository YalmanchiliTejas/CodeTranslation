#include<iostream>
#include<set>
using namespace std;
int N;
main()
{
	cin>>N;
	multiset<int>S;
	for(int i=0;i<N;i++)S.insert(-1);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;
		multiset<int>::iterator it=S.lower_bound(A);
		it--;
		if(*it==-1)ans++;
		S.erase(it);
		S.insert(A);
	}
	cout<<ans<<endl;
}
