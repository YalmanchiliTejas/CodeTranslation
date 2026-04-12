#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=9223372036854775806;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll h,w,i,j,k;
	bool q,r[100],c[100];
	fill(r,r+100,true);
	fill(c,c+100,true);
	cin>>h>>w;
	char a[h][w];
	for (i=0;i<h;i++){
		cin>>a[i];
	}
	for (i=0;i<h;i++){
		q=true;
		for (j=0;j<w;j++){
			if (a[i][j]=='#'){
				q=false;
			}
		}
		if (q==true){
			r[i]=false;
		}
	}
	for (i=0;i<w;i++){
		q=true;
		for (j=0;j<h;j++){
			if (a[j][i]=='#'){
				q=false;
			}
		}
		if (q==true){
			c[i]=false;
		}
	}
	for (i=0;i<h;i++){
		q=false;
		for (j=0;j<w;j++){
			if (r[i]==true&&c[j]==true){
		    	cout<<a[i][j];
		    	q=true;
		    }
		}
		if (q==true){
			cout<<"\n";
		}
	}
	return 0;
}