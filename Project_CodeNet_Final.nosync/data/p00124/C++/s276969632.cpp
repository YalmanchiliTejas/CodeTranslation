#include<algorithm>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n,f=0;
	while(cin>>n,n){
		if(f)cout<<endl; f=1;
		pair<int,pair<int,char[29]> > team[10];
		int w,l,d;
		rep(i,n){
			cin>>team[i].second.second>>w>>l>>d;
			team[i].first=-w*3-d;
			team[i].second.first=i;
		}
		sort(team,team+n);
		rep(i,n)cout<<team[i].second.second<<","<<-team[i].first<<endl;
	}
	return 0;
}