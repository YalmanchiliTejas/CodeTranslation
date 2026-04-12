#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define INF 1e8
#define EPS 1e-9

#define rep(i,n) for(int i=0;i<n;i++)

char c[]={'y','u','i','o','p','h','j','k','l','n','m'};
string s;

int main(){
	while(cin>>s&&s!="#"){
		int ans=0,pre=2,l=s.size();
		rep(i,l){
			int r=0;
			rep(j,11)if(s[i]==c[j])r=1;
			if(r==0&&pre==1||r==1&&pre==0)ans++;
			pre=r;
		}
		cout<<ans<<endl;
	}
}