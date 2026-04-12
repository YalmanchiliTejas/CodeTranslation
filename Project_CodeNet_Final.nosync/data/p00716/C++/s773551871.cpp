#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;

int main(){
	int m;
	cin >> m;
	int mx=0;
	int f,y,n;
	int i,j,k;
	for(i=0;i<m;i++){
		cin >> f >> y>>n;
		mx=0;
		for(j=0;j<n;j++){
			int ri,tes;
			double r;
			cin >> ri >> r >> tes;
			
			int tmp=f;
			int risi=0;
			for(k=0;k<y;k++){
				if(ri==0){
					risi+=(tmp*r);
				}else{
					tmp*=(1+r);
				}
				tmp-=tes;
			}
			mx=max(mx,tmp+risi);
		}
		cout << mx << endl;
	}
	
	return 0;
}
	