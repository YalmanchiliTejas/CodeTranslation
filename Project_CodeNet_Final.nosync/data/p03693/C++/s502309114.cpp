#include <bits/stdc++.h>

#include <cstdlib>  // abs() for integer 絶対値求めやつ

#include <cmath>    // abs() for float, and fabs()

#include <algorithm>
#include <vector>
#define rep(i,n) for(int i = 0; i< (n);i++)

#define SORT(a) sort((a).begin(),(a).end());

#define che(a,string) cout<<string<<":"<<(a)<<endl;

#define ch(a,string) cout<<string<<":"<<(a)<<" ";

using namespace std;

typedef pair<int,int> p;

int main(){
	int r,g,b;
	cin>>r>>g>>b;
	int a =100*r+10*g+b;
	if(a%4==0){
		cout<<"YES"<<endl;
	  }
	  else{
		  cout<<"NO"<<endl;
		}
  }
