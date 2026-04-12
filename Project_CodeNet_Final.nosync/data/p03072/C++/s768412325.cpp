#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,rt=0,cnt=1;
	bool jud=false;

	cin>>n;

	int h[n];

	for(int i=0;i<n;i++){
		cin>>h[i];
		if(i>0){
			for(int j=0;j<rt;j++){
				if(h[i]>=h[i-1]){
					if(h[i]>=h[j]){
						jud=true;
					}
					else{
						jud=false;
						break;
					}
				}
				else{
					jud=false;
				}
			}
		}
		if(jud) cnt++;
		rt++;
	}

	cout<<cnt<<endl;

	return 0;
}
