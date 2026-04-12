#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int k,m,g,y,n;
	cin >> k;
	for(int i=0;i<k;i++){
		int mg=0;
		cin >> g >> y >> n;
		for(int j=0;j<n;j++){
			int ng=g;
			int tf,q;
			double p;
			cin >> tf >> p >> q;
			if(tf){//単利
				for(int ii=0;ii<y;ii++)
					ng+=(int)(ng*p)-q;
			}else{//複利
				int r=0;
				for(int ii=0;ii<y;ii++){
					r+=(int)(ng*p);
					ng-=q;
				}
				ng+=r;
			}
			mg=max(mg,ng);
		}
		cout << mg << endl; 
	}

	return 0;
}