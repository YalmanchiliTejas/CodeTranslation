#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 1000005


int main(int argc, char const *argv[])
{
	int x,y,z;
	cin>>x>>y>>z;
	int nz,ny;
	int ans=0;
	for (int i = 1; i < maxn; ++i){
		ny=i;
		nz=ny+1;
		if(y*ny+z*nz<=x && y+2*z<=x){
			ans=ny;
			//cout<<"ny="<<ny<<"nz="<<nz<<endl;
		}
		if(y*ny+z*nz>x) break;
	}

	cout<<ans<<endl;

	return 0;
}