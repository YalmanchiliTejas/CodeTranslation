#include<iostream>
#include<algorithm>
#include<vector>
typedef long long lint;
using namespace std;

int main()
{
	lint N,A[100010];
	lint n,front,back;
	vector<lint> ans1,ans2;
	lint sum1=0,sum2=0;
	
	cin >> N;
	n=N/2;
	if(N%2==0)n--;
	for(lint i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	
	//ans1
	ans1.push_back(A[n]);
	front=0;
	back=N-1;
	for(lint i=0;i<n;i++)
	{
		ans1.push_back(A[front]);
		ans1.push_back(A[back]);
		front++;
		back--;
	}
	if(N%2==0)
		ans1.push_back(A[n+1]);
	
	//ans2
	ans2.push_back(A[n]);
	front=0;
	back=N-1;
	for(lint i=0;i<n;i++)
	{
		ans2.push_back(A[back]);
		ans2.push_back(A[front]);
		front++;
		back--;
	}
	if(N%2==0)
		ans2.push_back(A[n+1]);
	
	//prlint
	/*
	for(lint i=0;i<ans1.size();i++)
		cout << ans1[i] << " ";
	cout << endl;
	for(lint i=0;i<ans2.size();i++)
		cout << ans2[i] << " ";
	cout << endl;
	*/
	//ans
	for(lint i=0;i<ans1.size()-1;i++)
		sum1+=abs(ans1[i+1]-ans1[i]);
	for(lint i=0;i<ans2.size()-1;i++)
		sum2+=abs(ans2[i+1]-ans2[i]);
	
	cout << max(sum1,sum2) << endl;
}