#include<iostream>
#include<string>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

struct league{
	string name;
	int win,lose,draw,point;	
};

int main(){
	int n,cnt=0;
	while(cin>>n,n){
		if(cnt>0)cout<<endl;
		league inp[n],alt;
		string s;
		int w,l,d;
		rep(i,n){
			cin>>s>>w>>l>>d;
			inp[i].name=s;
			inp[i].win=w;
			inp[i].lose=l;
			inp[i].draw=d;
			inp[i].point=inp[i].win*3+inp[i].draw;
		}
		rep(i,n){
			for(int j=n-2;j>=i;j--){
				if(inp[j+1].point>inp[j].point){
					alt=inp[j+1];
					inp[j+1]=inp[j];
					inp[j]=alt;
				}
			}
		}
		rep(i,n){
			cout<<inp[i].name<<","<<inp[i].point<<endl;
		}
		cnt++;
	}
	return 0;
}