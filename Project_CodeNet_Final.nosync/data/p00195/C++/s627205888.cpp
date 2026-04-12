#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
	vector<int>in(5);
	int a,b;
	while(cin>>a>>b,a||b){
		in[0]=a+b;
		loop(i,1,5){
			cin>>a>>b;
			in[i]=a+b;
		}
		int maxi=0;
		rep(i,5)maxi=max(maxi,in[i]);
		rep(i,5)if(maxi==in[i])cout<<(char)('A'+i)<<" "<<in[i]<<endl;
	}
}