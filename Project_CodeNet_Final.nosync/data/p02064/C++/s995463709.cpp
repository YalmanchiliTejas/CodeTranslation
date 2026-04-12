#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

int dis[305][2];
vector<P> vs;

int main(){
	int n,p,q;
	int i,j,k;
	int a,b,c,d;
	cin>>n>>p>>q;
	cout<<"? "<<p<<" "<<q<<endl;
	cout.flush();
	cin>>a;
	p--,q--;
	dis[q][0]=a,dis[p][1]=a;
	vs.push_back(make_pair(0,p)),vs.push_back(make_pair(a,q));
	for(i=0;i<n;i++){
		if(i==p || i==q)continue;
		cout<<"? "<<i+1<<" "<<p+1<<endl;
		cout.flush();
		cin>>dis[i][0];
		cout<<"? "<<i+1<<" "<<q+1<<endl;
		cout.flush();
		cin>>dis[i][1];
		if(dis[i][0]+dis[i][1]==a)vs.push_back(make_pair(dis[i][0],i));
	}
	sort(vs.begin(),vs.end());
	a=p;
	for(i=1;i<vs.size();){
		b=vs[i].second;
		cout<<"? "<<a+1<<" "<<b+1<<endl;
		cout.flush();
		cin>>c;
		if(c!=dis[b][0]-dis[a][0]){
			vs.erase(vs.begin()+i);
		}else{
			a=b,i++;
		}
	}
	cout<<"!";
	for(i=0;i<vs.size();i++){
		cout<<" "<<vs[i].second+1;
	}
	cout<<endl;
		
}

