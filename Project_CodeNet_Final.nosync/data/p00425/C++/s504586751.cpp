#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#define shosu(x) fixed<<setprecision(x)
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> pip;
const int inf=(1<<31)-1;

int n;

int main(){
	while(1){
		cin>>n;
		if(!n) break;
		int ans=1;
		int up=1,lef=2,rig=3;
		for(int i=0;i<n;i++){
			string str;
			int tmp;
			cin>>str;
			if(str=="North"){
				tmp=up;
				up=lef;
				lef=7-tmp;
			}
			else if(str=="East"){
				tmp=rig;
				rig=up;
				up=7-tmp;
			}
			else if(str=="West"){
				tmp=up;
				up=rig;
				rig=7-tmp;
			}
			else if(str=="South"){
				tmp=lef;
				lef=up;
				up=7-tmp;
			}
			else if(str=="Right"){
				tmp=lef;
				lef=rig;
				rig=7-tmp;
			}
			else if(str=="Left"){
				tmp=rig;
				rig=lef;
				lef=7-tmp;
			}
			ans+=up;
		}
		cout<<ans<<endl;
	}
}