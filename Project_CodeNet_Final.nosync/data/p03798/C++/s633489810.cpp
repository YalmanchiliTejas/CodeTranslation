#include<bits/stdc++.h>
using namespace std;
char str[100100];
bool shp[100100];
int n;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	scanf("%s",str);
	for(int mask=0;mask<4;mask++){
		shp[0]=(mask&1);
		shp[1]=(mask>>1)&1;
		for(int j=1;j<n-1;j++){
			shp[j+1]=shp[j-1]^shp[j]^(str[j]=='x');
		}
		if(shp[0]==shp[n-2]^shp[n-1]^(str[n-1]=='x')){
			if(shp[1]==shp[n-1]^shp[0]^(str[0]=='x')){
				for(int i=0;i<n;i++){
					if(shp[i])
						cout<<'W';
					else
						cout<<'S';
				}
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}