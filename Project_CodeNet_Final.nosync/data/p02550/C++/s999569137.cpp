#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,x,m;
	cin>>n>>x>>m;
	vector<ll>arr;
	arr.push_back(x);
	ll var=x;
	vector<int>visited(m);
	visited[var]=1;
	ll rep;
	vector<ll>ans;
	ans.push_back(x);
	while(true)
	{
		var=var*var%m;
		if(visited[var]){
			rep=var;
			break;
		}
		else{
			ans.push_back(var);
			visited[var]=1;
		}
	}
    ll cnt1=0,cnt2=0;
    int ch=0;
    ll sum1=0,sum2=0;
    for(int nums : ans)
    {
    //	cout<<nums<<" ";
    	if(nums==rep){
    		ch=1;
		}
		if(ch==0){
		 cnt1++;
		 sum1+=nums;
	    }
		if(ch==1){
		 cnt2++;
		 sum2+=nums;
	    }
	}
	cout<<"\n";
	ll num1=min(n,cnt1);
	n-=num1;
	ll num2=n/cnt2;
	ll num3=n%cnt2;
	ll final=0;
	for(int i=0; i<num1; i++)
	 final+=ans[i];
	final+=num2*sum2;
	for(int i=cnt1; i<cnt1+num3; i++)
	 final+=ans[i];
	cout<<final;
	return 0;
}