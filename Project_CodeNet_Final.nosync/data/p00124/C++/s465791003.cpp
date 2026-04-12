#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int n;
	int co=0;
	while(cin>>n,n){
		if(co)cout<<endl;
		co++;
		vector<string>s(n);
		vector<int>in(n);
		rep(i,n){
			int a,b,c;
			cin>>s[i]>>a>>b>>c;
			in[i]=a*3+c;
		}
		rep(i,n)for(int j=n-2;j>=i;j--)if(in[j]<in[j+1]){
			swap(s[j],s[j+1]);
			swap(in[j],in[j+1]);
		}
		rep(i,n)cout<<s[i]<<","<<in[i]<<endl;
	}
}