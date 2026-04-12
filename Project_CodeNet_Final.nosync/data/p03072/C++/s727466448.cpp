#include<iostream>
using namespace std;
int main()
{
	int awal,index,nilai,org;
	index=0;
	cin>>awal;
	org=awal+1;
	int arr[org];
	for (int i=1;i<=awal;i++) {
		cin>>nilai;
		arr[i]=nilai;
	}
	arr[org]=arr[1];
	for (int j=1;j<=awal;j++) {
		if (arr[j]>=arr[org]) {
			index++;
			arr[org]=arr[j];
		}
	}
	cout<<index<<endl;
	return 0;
}