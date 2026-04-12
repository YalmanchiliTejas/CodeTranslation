//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll def=1;
	for(int i=0;i<18;i++)def*=10;
	vector<ll> v(n),v1(n),v2(n),u(n),u1(n),u2(n);
	v[0]=a[0];
	v1[0]=-def;
	v2[0]=-def;
	u[0]=-def;;
	u1[0]=0;
	u2[0]=-def;
	for(int i=1;i<n;i++){
		v[i]=u[i-1]+a[i];
		v1[i]=u1[i-1]+a[i];
		v2[i]=u2[i-1]+a[i];
		u[i]=v[i-1];
		u1[i]=max(v1[i-1],u[i-1]);
		u2[i]=max(v2[i-1],u1[i-1]);
	}
	if(n%2){
		cout<<max(v2[n-1],u1[n-1])<<endl;
	}else{
		cout<<max(v1[n-1],u[n-1])<<endl;
	}
//	for(int i=0;i<n;i++){
//		cout<<v[i]<<' ';
//	}cout<<endl;
//	for(int i=0;i<n;i++){
//			cout<<v[i]<<' ';
//		}cout<<endl;
//		for(int i=0;i<n;i++){
//				cout<<v1[i]<<' ';
//			}cout<<endl;
//			for(int i=0;i<n;i++){
//					cout<<v2[i]<<' ';
//				}cout<<endl;
//				for(int i=0;i<n;i++){
//						cout<<u[i]<<' ';
//					}cout<<endl;
//					for(int i=0;i<n;i++){
//							cout<<u1[i]<<' ';
//						}cout<<endl;
//						for(int i=0;i<n;i++){
//								cout<<u2[i]<<' ';
//							}cout<<endl;
	return 0;
}