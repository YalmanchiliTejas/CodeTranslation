#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int n,m,time[20010],ma,tmp;
	while(cin>>n>>m,n+m){
		ma=0;
		tmp=0;
	for(int i=0;i<n;i++)cin>>time[i];
		for(int i=n;i<n+m;i++)cin>>time[i];
		sort(time,time+(n+m-1));
		for(int i=0;i<n+m;i++){
			ma=max(ma,(time[i]-tmp));
			tmp=time[i];
		}
		cout<<ma<<endl;
	}
}