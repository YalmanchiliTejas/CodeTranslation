#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define mkp make_pair
#define F first
#define S second
typedef pair<int,int> pii;

map<pii,pii> N,R;

int main(){
	N[mkp(1,2)]=mkp(2,6);
	N[mkp(1,3)]=mkp(3,6);
	N[mkp(1,4)]=mkp(4,6);
	N[mkp(1,5)]=mkp(5,6);
	N[mkp(2,1)]=mkp(1,5);
	N[mkp(2,3)]=mkp(3,5);
	N[mkp(2,4)]=mkp(4,5);
	N[mkp(2,6)]=mkp(6,5);
	N[mkp(3,1)]=mkp(1,4);
	N[mkp(3,2)]=mkp(2,4);
	N[mkp(3,5)]=mkp(5,4);
	N[mkp(3,6)]=mkp(6,4);
	N[mkp(4,1)]=mkp(1,3);
	N[mkp(4,2)]=mkp(2,3);
	N[mkp(4,5)]=mkp(5,3);
	N[mkp(4,6)]=mkp(6,3);
	N[mkp(5,1)]=mkp(1,2);
	N[mkp(5,3)]=mkp(3,2);
	N[mkp(5,4)]=mkp(4,2);
	N[mkp(5,6)]=mkp(6,2);
	N[mkp(6,2)]=mkp(2,1);
	N[mkp(6,3)]=mkp(3,1);
	N[mkp(6,4)]=mkp(4,1);
	N[mkp(6,5)]=mkp(5,1);



	R[mkp(1,2)]=mkp(1,3);
	R[mkp(1,3)]=mkp(1,5);
	R[mkp(1,4)]=mkp(1,2);
	R[mkp(1,5)]=mkp(1,4);
	R[mkp(2,1)]=mkp(2,4);
	R[mkp(2,3)]=mkp(2,1);
	R[mkp(2,4)]=mkp(2,6);
	R[mkp(2,6)]=mkp(2,3);
	R[mkp(3,1)]=mkp(3,2);
	R[mkp(3,2)]=mkp(3,6);
	R[mkp(3,5)]=mkp(3,1);
	R[mkp(3,6)]=mkp(3,5);
	R[mkp(4,1)]=mkp(4,5);
	R[mkp(4,2)]=mkp(4,1);
	R[mkp(4,5)]=mkp(4,6);
	R[mkp(4,6)]=mkp(4,2);
	R[mkp(5,1)]=mkp(5,3);
	R[mkp(5,3)]=mkp(5,6);
	R[mkp(5,4)]=mkp(5,1);
	R[mkp(5,6)]=mkp(5,4);
	R[mkp(6,2)]=mkp(6,4);
	R[mkp(6,3)]=mkp(6,2);
	R[mkp(6,4)]=mkp(6,5);
	R[mkp(6,5)]=mkp(6,3);
	
	int n;
	while(cin>>n,n){
		pii now=mkp(1,2);
		int ans=1;
		rep(i,n){
			string tmp;
			cin>>tmp;
			// cout<<ans<<endl;
			if(tmp=="North"){
				now=N[now];
				ans+=now.F;
				// cout<<now.F<<" "<<now.S<<endl;
			}
			else if(tmp=="East"){
				rep(i,3) now=R[now];
				now=N[now];
				ans+=now.F;
				now=R[now];
				// cout<<now.F<<" "<<now.S<<endl;
			}
			else if(tmp=="South"){
				rep(i,3) now=N[now];
				ans+=now.F;
				// cout<<now.F<<" "<<now.S<<endl;

			}
			else if(tmp=="West"){
				now=R[now];
				now=N[now];
				ans+=now.F;
				rep(i,3) now=R[now];
				// cout<<now.F<<" "<<now.S<<endl;

			}
			else if(tmp=="Right"){
				now=R[now];
				ans+=now.F;
				// cout<<now.F<<" "<<now.S<<endl;

			}
			else if(tmp=="Left"){
				rep(i,3) now=R[now];
				ans+=now.F;
				// cout<<now.F<<" "<<now.S<<endl;

			}
		}
		cout<<ans<<endl;
	}
	return 0;
}