#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int get_time(int a, int b) {
	if(a>b)swap(a,b);
	if(a+20<b)return b;
	else {
		return (a+b+20)/2;
	}
}

int main() {
	int N;cin>>N;
	vector<pair<int,int>>coors(N);
	vector<pair<int,int>>real_coors(N);
	for (int i = 0; i < N; ++i) {
		int x,y;cin>>x>>y;
		x+=1e8+1000;
		y+=1e8+1000;
		x*=2;
		y*=2;
		coors[i]=make_pair(x-y,x+y);
		real_coors[i]=make_pair(x,y);
	}
	int u=1e9;
	int d=-1e9;
	int l=1e9;
	int r=-1e9;
	for (auto co : coors) {
		u=min(u,co.second);
		d=max(d,co.second);
		l=min(l,co.first);
		r=max(r,co.first);
	}

	int c_x=(l+r)/2;
	int c_y=(d+u)/2;

	int real_c_x=(c_x+c_y)/2;
	int real_c_y=(c_y-c_x)/2;

	{
		int real_c_l=(real_c_x)/20*20-20;
		int real_c_u=(real_c_y)/20*20-20;
		int real_c_d=(real_c_u)+20;

		
		int ans=1e9;
		for(int dx=0;dx<=60;++dx){
			for (int dy = 0; dy <= 60; ++dy) {
				if (dx%20==0||dy%20==0) {

					int nx=real_c_l+dx;
					int ny=real_c_u+dy;
					int nans=0;
					bool flag=(dx%20==0&&dy%20==0);
					for (auto rc : real_coors) {

						int x_cost;
						if (ny!=rc.second&&!flag&&rc.first/20 == nx / 20) {
							int a=rc.first%20;
							int b=nx%20;
							x_cost=min(a+b,40-a-b);
						}
						else {
							x_cost=abs(rc.first-nx);
						}
						int y_cost;
						if (nx!=rc.first&&!flag&&rc.second / 20 ==ny / 20) {
							int a = ny % 20;
							int b = rc.second % 20;
							y_cost = min(a + b, 40 - a - b);
						}
						else {
							y_cost = abs(rc.second - ny);
						}
						nans=max(nans,x_cost+y_cost);
					}
					ans=min(ans,nans);
				}
			}
		}
		cout<<setprecision(10)<<fixed<<double(ans)/2<<endl;
	}


	return 0;
}
