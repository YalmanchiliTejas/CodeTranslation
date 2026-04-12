#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
int n,num,ans,x;
vector<P>v;
main(){
	while(cin>>n,n){
	v.clear();
	ans=0;
	r(i,n){
		num=v.size()-1;
		cin>>x;
		if(i%2==0){
			if(i==0)v.push_back(P(1,x));
			else{
				if(v[num].second==x)v[num].first++;
				else v.push_back(P(1,x));
			}
		}
		else{
			if(v[num].second==x)v[num].first++;
			else{
				int t=v[num].first;
				v.erase(v.begin()+num);
				if(v.size())v[num-1].first+=t+1;
				else v.push_back(P(t+1,x));
			}
		}
	}
	r(i,v.size())if(v[i].second==0)ans+=v[i].first;
	cout<<ans<<endl;
    }
}