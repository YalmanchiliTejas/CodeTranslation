#include<iostream>
#include<algorithm>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,pair<int,int> > PP;
int n;
int p[100010];
pair<int,int> x[100010],y[100010];
priority_queue<PP,vector<PP>,greater<PP> >Q;

bool Same(int a,int b){
	int k=a;
	while(true){if(p[k]==k)break;k=p[k];}
	while(true){if(p[a]==a)break;a=p[a],p[a]=k;}
	int l=b;
	while(true){if(p[l]==l)break;l=p[l];}
	while(true){if(p[b]==b)break;b=p[b],p[b]=l;}
	
	if(k==l)return true;
	return false;
}

void Unite(int a,int b){
	int k=a;
	while(true){if(p[k]==k)break;k=p[k];}
	while(true){if(p[a]==a)break;a=p[a],p[a]=k;}
	int l=b;
	while(true){if(p[l]==l)break;l=p[l];}
	while(true){if(p[b]==b)break;b=p[b],p[b]=l;}
	
	p[k]=p[l];
	return;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;a--,b--;
		x[i]=make_pair(a,i);
		y[i]=make_pair(b,i);
	}
	sort(x,x+n);sort(y,y+n);
	for(int i=0;i<n-1;i++){
		Q.push(make_pair(x[i+1].X-x[i].X,make_pair(x[i].Y,x[i+1].Y)));
		Q.push(make_pair(y[i+1].X-y[i].X,make_pair(y[i].Y,y[i+1].Y)));
	}
	for(int i=0;i<n;i++)p[i]=i;
	int ans=0;
	while(!Q.empty()){
		if(!Same(Q.top().Y.X,Q.top().Y.Y)){
			ans+=Q.top().X;
			Unite(Q.top().Y.X,Q.top().Y.Y);
		}
		Q.pop();
	}
	cout<<ans<<endl;
	return 0;
}
