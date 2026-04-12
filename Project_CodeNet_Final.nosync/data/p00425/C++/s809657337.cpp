#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

int n;
string s;

int main(){
	while(cin>>n){
		if(n==0)return 0;
		int t=1,f=2,r=3,ans=1;
		for(int i=0;i<n;i++){
			cin>>s;
			if(s=="North"){swap(t,f);f=7-f;}
			if(s=="East"){swap(t,r);t=7-t;}
			if(s=="West"){swap(t,r);r=7-r;}
			if(s=="South"){swap(t,f);t=7-t;}
			if(s=="Right"){swap(f,r);r=7-r;}
			if(s=="Left"){swap(f,r);f=7-f;}
			ans+=t;
		}
		cout<<ans<<endl;
	}
}