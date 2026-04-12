#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<iostream>
using namespace std;

int k;
double r;
int t;

int first;
int y,n;

int cal(){
	int fb=first;
	if(k==0){
		int p=0;
		for(int i=0;i<y;i++){
			p+=(int)(fb*r);
			fb-=t;
		}
		fb+=p;
	}
	else{
		for(int i=0;i<y;i++){
			fb+=((int)(fb*r)-t);
		}
	}
	return fb;
}

int i_max(int p,int q){
	if(p>q) return p;
	return q;
}

int main(){
	int nn;
	int i;
	int ans;
	int size;
	cin>>size;
	for(nn=0;nn<size;nn++){
		cin>>first>>y>>n;
		ans=0.0;
		for(i=0;i<n;i++){
			cin>>k>>r>>t;
			ans=i_max(ans,cal());
		}
		cout<<ans<<endl;
	}
}