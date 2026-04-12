#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f[5009],pas=1;
vector <pair <int, int> > v[5009];
vector <pair <int, int> >::iterator it;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	for(b=1; b<=a; b++) cin>>f[b];
	sort(f+1,f+a+1);
	for(b=a-1; b>=1; b--){
		for(c=b+1; c<=a; c++){
			if(v[c].size()==0){
				v[b].push_back(make_pair(f[c]-f[b],2));
				if(pas<2) pas=2;
				continue;
			}
			it=lower_bound(v[c].begin(),v[c].end(),make_pair(f[c]-f[b],0));
			if(it==v[c].end()||(*it).first>f[c]-f[b]){
				v[b].push_back(make_pair(f[c]-f[b],2));
				if(pas<2) pas=2;
			}else{
				v[b].push_back(make_pair(f[c]-f[b],(*it).second+1));
				if(pas<(*it).second+1) pas=(*it).second+1;
			}
		}
	}
	cout<<pas<<endl;
	return 0;
}
