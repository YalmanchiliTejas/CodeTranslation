#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

int main(){
	int n;
	while(cin>>n){
		if(!n)break;

		int magic[n][n];
		for(int i=0;i<n*n;i++)
			magic[i/n][i%n] = 0;

		int x = n/2,y = (n+1)/2;
		for(int i=0;i<n*n;i++){
			magic[y][x] = i+1;
			y = (++y)%n;
			x = (++x)%n;
			if(magic[y][x]!=0){
				y = (++y)%n;
				x += n-1;
				x %= n;
			}
		}
	
		
		for(int y = 0;y<n;y++){
			for(int x = 0;x<n;x++){
				printf("%4d",magic[y][x]);
			}
			cout<<endl;
		}
		
	}
  return 0;
}